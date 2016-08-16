/*
 *
 */

#include "processoIOQueue.h"

void carregarFilaProcessos(processoIOQueue *fila, char processos[]) {
    enqueue(fila,(processoIO){1,{10,20},{115},0});
    enqueue(fila,(processoIO){2,{8,5,5},{15,10},0});
    enqueue(fila,(processoIO){3,{40},{},0});
}

int esperandoIO(processoIO *processo) {
    for (int i = 0; i < (sizeof(processo->processamento)/sizeof(int)); i++) {
        if (processo->processamento[i]<=0 && processo->io[i]>0) {
            return 1;
        }
    }
    return 0;
}

//Retorna a posição do vetor
int getPosProcessamento(processoIO *processo) {
    for (int i = 0; i < (sizeof(processo->processamento)/sizeof(int)); i++) {
        if (processo->processamento[i]>0){
            return i;
        }
    }
    return -1;
}

//Retorna a posição do vetor que possui espera de IO
int getPosEsperandoIO(processoIO *processo) {
    for (int i = 0; i < (sizeof(processo->io)/sizeof(int)); i++) {
        if (processo->processamento[i]<=0 && processo->io[i]>0){
            return i;
        }
    }
    return -1;
}

void decrementaTempoEsperaIO(processoIOQueue *fila) {
    for (int i = 0; i < size(fila); i++) {
        //fila->elements[get(fila,i)].io[getPosEsperandoIO(fila->elements[get(fila,i)])]--;
        get(fila,i)->io[getPosEsperandoIO(get(fila,i))]--;
    }
}

int processoAcabou(processoIO *processo) {
    for (int i = 0; i < (sizeof(processo->processamento)/sizeof(int)); i++) {
        if (processo->processamento[i]>0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    processoIOQueue fila;
    init(&fila,1);

    char processos[] = "10,115,20;8,15,5,10,5;40";

    carregarFilaProcessos(&fila,processos);

    int tempo=0;

    while (!isEmpty(&fila)) {
        processoIO p = dequeue(&fila);
        if (esperandoIO(&p)) {
            enqueue(&fila,p);
            tempo++;
            decrementaTempoEsperaIO(&fila);
        } else {
            printf("Alocado processo: %d no tempo: %d\n",p.id,tempo);
            // Faz processamento
            int posicaoProcessamento = getPosProcessamento(&p);
            p.numAlocacoes++;
            int termino = p.processamento[posicaoProcessamento];
            for (int i = 0; i < termino; i++) {
                tempo++;
                p.processamento[posicaoProcessamento]--;
                decrementaTempoEsperaIO(&fila);
            }
            if (!processoAcabou(&p)) enqueue(&fila, p);
        }
    }


    printf("Tempo total de processamento: %d\n",tempo);
    printf("\n\n");

    return 0;
}
