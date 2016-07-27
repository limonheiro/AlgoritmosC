/*
 * filaatendimentov2.c
 *
 *  Created on: 5 de jul de 2016
 *      Author: joaopaulodelgadopreti
 */
/*
#include "regClienteQueue.h"
#include <string.h>

#define CAIXAS 2
#define HORARIO_ENCERRAMENTO_EXPEDIENTE 10000

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
	regClienteQueue fila;
	init(&fila,1);

	enqueue(&fila,(regCliente){1,0,15});
	enqueue(&fila,(regCliente){2,0,10});
	enqueue(&fila,(regCliente){3,0,5});
	enqueue(&fila,(regCliente){4,0,6});
	enqueue(&fila,(regCliente){5,0,15});
	enqueue(&fila,(regCliente){6,0,11});
	enqueue(&fila,(regCliente){7,0,9});
	enqueue(&fila,(regCliente){8,0,8});
	enqueue(&fila,(regCliente){9,0,12});
	enqueue(&fila,(regCliente){10,0,7});

	char clientesFuturos[] = "25,12,8,3,14,12,25,6,1,4,11,9,19,18,7,7,3,2,1,9,2,6,13,17,12,15,23,32,7,3,9,4,13";
	char* clienteToken = strtok(clientesFuturos,",");

	int clienteCount=10;//já tem 10 clientes na fila
	int tempoFila = 0; //os 10 primeiros clientes chegaram quando a agência abriu.
	int tempoMaximoEspera = 0;
	int tempoTotalEspera = 0;

	while (!isEmpty(&fila) || tempoFila < HORARIO_ENCERRAMENTO_EXPEDIENTE) {
		if (tempoFila%7==0 && clienteToken!=NULL && tempoFila < HORARIO_ENCERRAMENTO_EXPEDIENTE) { // só pode entrar na fila se dentro do horário do expediente
			int tempo;
			sscanf(clienteToken, "%d", &tempo);
			enqueue(&fila,(regCliente){++clienteCount,tempoFila,tempo});
			clienteToken = strtok(NULL,",");
		}

		int caixa = caixaLivre(caixas);
		if (caixa >= 0 && !isEmpty(&fila)) {
			regCliente cliente = dequeue(&fila);
			int tempoEspera = tempoFila-cliente.tempoChegada;
			printf("Cliente %d (tempo de espera %d) vá para o Caixa %d\n",cliente.id,tempoEspera,caixa+1);
			caixas[caixa]= cliente.tempoOcuparaCaixa;
			tempoCaixas[caixa] += cliente.tempoOcuparaCaixa;
			if (tempoEspera>tempoMaximoEspera) tempoMaximoEspera = tempoEspera;
			tempoTotalEspera+=tempoEspera;
		}
		for (int i = 0; i < CAIXAS; i++)
			if (caixas[i]!=0)
				caixas[i]--;
		tempoFila++;
	}

	printf("\n");

	for (int i = 0; i < CAIXAS; i++)
		printf("Tempo do caixa %d: %d\n",i+1,tempoCaixas[i]);

	printf("\n");

	printf("Tempo médio de espera: %d\n",tempoTotalEspera/clienteCount);
	printf("Maior tempo de espera: %d\n",tempoMaximoEspera);
	return 0;
}
*/

