/**************************************************************************
 * Programa prioridadeexpressao.c	                                      *
 *                                                                        *
 * Verificando a corretude na prioridade das expressões com pilha		  *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/
/*d
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cStack.h"

int in(char elemento, char elementos[]) {
	for (int i = 0; elementos[i]!=0; i++)
		if (elemento == elementos[i])
			return i;
	return -1;
}

int avaliarAberturaEncerramento(char expressao[], char charsAbertura[], char charsEncerramento[]) {
	cStack pilha;
	init(&pilha,1);

	for (int i = 0 ; expressao[i] != 0 ; i++) {
		if (in(expressao[i],charsAbertura)>=0)
			push(&pilha,expressao[i]);

		if (in(expressao[i],charsEncerramento)>=0) {
			if (!isEmpty(&pilha)) {
				if (in(pop(&pilha),charsAbertura) == in(expressao[i],charsEncerramento)) {
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

char* preencherEspacosAntes(int qtdeEspacos, char c) {
	char *texto = (char *) malloc(sizeof(char) * qtdeEspacos);
	for (int i = 0 ; i < qtdeEspacos ; i++)
		texto[i] = ' ';
	texto[qtdeEspacos-2] = c;
	texto[qtdeEspacos-1] = '\0';
	return texto;
}

int main() {

	char expressao[] = "41 . 30 : {23 . [52 – 23 . (4 - 3) - (3 . 5)]} : 5";

	int resultado = avaliarAberturaEncerramento(expressao, "{[(","}])");

	if (resultado>=0) {
		printf("Expressão Inválida!\n");
		printf("%s\n",expressao);
		printf("%s",preencherEspacosAntes(resultado, '^'));
	}
	else
		printf("Expressão Válida!");


	return EXIT_SUCCESS;
}
*/
