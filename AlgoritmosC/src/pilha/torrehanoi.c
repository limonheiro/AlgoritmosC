/**************************************************************************
 * Programa torrehanoi.c	                                              *
 *                                                                        *
 * Demonstracão do uso de pilha para resolver o problema da torre de hanoi*
 * Data: 30/05/2016			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iStack.h"

void mover(int num, iStack *origem, iStack *destino, iStack *aux) {

	push(destino,pop(origem));

	if (num == 1) {
        printf("\n Movendo disco %d de %d para %d", num, origem->id, destino->id);
	} else {
		mover(num-1,origem, aux, destino);
		printf("\n Movendo disco %d de %d para %d", num, origem->id, destino->id);
		mover(num-1, aux, destino, origem);
	}

}

int main() {

	iStack torres[3];

	init(&torres[0],1);
	init(&torres[1],2);
	init(&torres[2],3);

	push(&torres[0], 3);
	push(&torres[0], 2);
	push(&torres[0], 1);

	mover(size(&torres[0]), &torres[0], &torres[2], &torres[1]);
}
*/

