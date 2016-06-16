/*
 * InfixaPosfixa.c
 *
 *  Created on: 11 de jun de 2016
 *      Author: joaopaulodelgadopreti
 */
/*
#include "sStack.h"
#include <string.h>

int in(char *elemento, char elementos[]) {
	for (int i = 0; elementos[i] != 0; i++)
		if (*elemento == elementos[i])
			return 1;
	return 0;
}

int prio(char *op) {
	if (*op=='(') return 1;
	if (*op=='+' || *op=='-') return 2;
	if (*op=='*' || *op=='/') return 3;
	return -1;
}

char* posfixa(char *infixa) {
	sStack pilha;
	init(&pilha,1);
	char posfixa[100] = "";
	char *word;
	char buffer[10];

	word = strtok(infixa, " ");

	while (word != NULL) {
		if (in(word, "+/-*")) {
			while (!isEmpty(&pilha) && prio(top(&pilha))>=prio(word)){
				strcat(posfixa, pop(&pilha));
				strcat(posfixa, " ");
			}
			push(&pilha, word);
		} else if (word[0] == '(') {  (2 * 3 + 5) * 4
			//empilha o parenteses	saida= 2 3 * 5 + 4 *
			push(&pilha, "(");		pilha=
			//concatena na saída o número
			memcpy(buffer, &word[1], strlen(word) - 1);
			strcat(posfixa, buffer);
			strcat(posfixa, " ");
		} else if (word[strlen(word) - 1] == ')') {
			memcpy(buffer, &word[0], strlen(word) - 1);
			strcat(posfixa, buffer);
			strcat(posfixa, " ");
			while (strcmp(top(&pilha),"(")!=0){
				strcat(posfixa, pop(&pilha));
				strcat(posfixa, " ");
			}
			//descarta o parenteses
			pop(&pilha);
		} else {
			//concatena na saída o número
			strcat(posfixa, word);
			strcat(posfixa, " ");
		}
		word = strtok( NULL, " ");
	}
	while (!isEmpty(&pilha)) {
		strcat(posfixa, pop(&pilha));
		strcat(posfixa, " ");
	}

	return posfixa;
}

int main() {
	char infixa[] = "(222 + 333) * 5";
	printf("%s",posfixa(infixa));
	return 0;
}
*/
