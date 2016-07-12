/*
 * filaatendimento.c
 *
 *  Created on: 5 de jul de 2016
 *      Author: joaopaulodelgadopreti
 */
/*
#include "iQueue.h"

#define CAIXAS 3

void initZero(int vetor[]) {
	for (int i = 0; i < CAIXAS; i++)
		vetor[i] = 0;
}

int caixaLivre(int caixas[]) {
	for (int i = 0; i < CAIXAS; i++)
		if (caixas[i]==0)
			return i;
	return -1;
}

int main() {
	int caixas[CAIXAS], tempoCaixas[CAIXAS];
	initZero(caixas);
	initZero(tempoCaixas);
	iQueue fila;
	init(&fila,1);

	enqueue(&fila,15);
	enqueue(&fila,10);
	enqueue(&fila,5);
	enqueue(&fila,50);
	enqueue(&fila,15);
	enqueue(&fila,25);
	enqueue(&fila,20);
	enqueue(&fila,12);
	enqueue(&fila,18);
	enqueue(&fila,7);

	int cliente=0;
	int tempoFila = 0;

	while (!isEmpty(&fila)) {
		int caixa = caixaLivre(caixas);
		if (caixa >= 0) {
			printf("Cliente %d (tempo de espera %d) vá para o Caixa %d\n",++cliente,tempoFila,caixa+1);
			int tempoCliente = dequeue(&fila);
			caixas[caixa]= tempoCliente;
			tempoCaixas[caixa] += tempoCliente;
		}
		for (int i = 0; i < CAIXAS; i++)
			if (caixas[i]!=0)
				caixas[i]--;
		tempoFila++;
	}

	printf("\n");

	for (int i = 0; i < CAIXAS; i++)
		printf("Tempo do caixa %d: %d\n",i+1,tempoCaixas[i]);

	return 0;
}
*/

