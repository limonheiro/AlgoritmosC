/*
 * compilador.c
 *
 *  Created on: 28 de jun de 2016
 *      Author: joaopaulodelgadopreti
 */
#include <string.h>
#include "../../iStack.h"

void getInstrucao(char* instrucao, char* linha) {
	strcpy(instrucao, linha);
	strtok(instrucao," ");
}

char* getParametro(char* linha) {
	char* aux = strtok(linha," ");
	aux = strtok(NULL," ");
	return aux;
}

int getRoutinePosition(char* linhas[100], char *routine) {
	char rotina[50] = "routine ";
	strcat(rotina, routine);
	for (int i = 0; i < 100; i++) {
		if (strcmp(linhas[i],rotina)==0)
			return i;
	}

	return -1;
}

void print(char* linha) {
	char linhaAux[100];
	strcpy(linhaAux, linha);
	printf("%s\n",getParametro(linhaAux));
}

int main() {
	char programSource[250]="routine A\nprint \"1\"\ncall B\ncall C\nreturn\nroutine B\ncall C\nprint \"3\"\nreturn\nroutine C\nprint \"2\"\nreturn";

	char* linha = strtok(programSource,"\n");
	char* linhas[100];
	int linhasPrograma = 0;
	while (linha!=NULL) {
		linhas[linhasPrograma++] = linha;
		linha = strtok(NULL, "\n");
	}

	iStack pilhaExecucao;
	init(&pilhaExecucao,1);
	int contadorInstrucao=0;
	char instrucao[50];
	int termina = 0;
	while (!termina) {
		//printf("%d\n",contadorInstrucao+1);
		char* linhaExecucao = linhas[contadorInstrucao];
		contadorInstrucao++;
		getInstrucao(instrucao, linhaExecucao);
		if (strcmp(instrucao,"return")==0 && isEmpty(&pilhaExecucao)) {
			termina=1;
		}
		if (strcmp(instrucao,"routine")==0) {
			continue;
		}
		if (strcmp(instrucao,"print")==0) {
			print(linhaExecucao);
			continue;
		}
		if (strcmp(instrucao,"return")==0 && !isEmpty(&pilhaExecucao)) {
			contadorInstrucao = pop(&pilhaExecucao);
			continue;
		}
		if (strcmp(instrucao,"call")==0) {
			push(&pilhaExecucao,contadorInstrucao);
			contadorInstrucao=getRoutinePosition(linhas, getParametro(linhaExecucao));
			continue;
		}
	}

	return 0;
}
