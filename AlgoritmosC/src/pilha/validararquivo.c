/**************************************************************************
 * Programa validararquivo.c	                                          *
 *                                                                        *
 * Demonstracão do uso de pilha para ler um arquivo C e apontar a linha   *
 * com problemas de fechamento de parênteses ou chaves 					  *
 * Data: 30/05/2016			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cStack.h"

const int BUFFER_SIZE = 300; // quantidade de caracteres a serem lidos por vez
const int MAX_SIZE = 30000; // quantidade máxima de caracteres

int in(char elemento, char elementos[]) {
	for (int i = 0; elementos[i] != 0; i++)
		if (elemento == elementos[i])
			return i;
	return -1;
}

int avaliarAberturaEncerramento(char expressao[], char charsAbertura[],
		char charsEncerramento[]) {
	cStack pilha;
	init(&pilha,1);

	for (int i = 0; expressao[i] != 0; i++) {
		if (in(expressao[i], charsAbertura) >= 0)
			push(&pilha, expressao[i]);

		if (in(expressao[i], charsEncerramento) >= 0) {
			if (!isEmpty(&pilha)) {
				if (in(pop(&pilha), charsAbertura)
						== in(expressao[i], charsEncerramento)) {
					//Não faz nada. O pop ja foi executado.
				} else {
					return i;
				}
			} else {
				return i;
			}
		}
	}
	return -1;

}

int main(int argc, char *argv[]) {
	FILE *arquivo = fopen("src/pilha/palindroma.c", "r");
	char buffer[BUFFER_SIZE];
	char textoCompleto[MAX_SIZE];

	if (arquivo != NULL) {
		int linha = 1;
		while (fgets(buffer, BUFFER_SIZE, arquivo)) {
			strcat(textoCompleto,buffer);
			printf("%d: %s\n", linha, buffer);
			linha++;
		}

		int resultado = avaliarAberturaEncerramento(textoCompleto, "{[(", "}])");

		if (resultado >= 0) {
			int linhaErro = 1;
			for (int i = 0; i < resultado; i++)
				if (textoCompleto[i]=='\n')
					linhaErro++;

			printf("ERRO na linha: %d\n", linhaErro);
		}

		fclose(arquivo);
	} else
		printf("Nao foi possivel abrir o arquivo.");

	printf("\n\n");
	return 0;
}





























/*
		//copiaVetor(buffer, textoCompleto, (linha - 1) * 300, 300);
		//int tamanhoArquivo = ftell(arquivo);
		//for (int i = 0; i < tamanhoArquivo; i++) printf("%c",textoCompleto[i]);

void copiaVetor(char vetorOrigem[], char vetorDestino[], int posInicial,
		int tamanho) {
	for (int i = 0; i < tamanho; i++)
		vetorDestino[posInicial + i] = vetorOrigem[i];
}
*/














