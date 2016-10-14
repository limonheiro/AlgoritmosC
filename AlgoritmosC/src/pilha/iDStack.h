/*
 * iDStack.h
 *
 *  Created on: 6 de out de 2016
 *      Author: joaopaulodelgadopreti
 */

#ifndef PILHA_IDSTACK_H_
#define PILHA_IDSTACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int data;
    struct No *next;
}No;

typedef struct iDStack {
    No *top;
    int size;
}iLinkedList;

void init	(iLinkedList *stack);
int push	(iLinkedList *stack, int data);
int pop		(iLinkedList *stack);
int top		(iLinkedList *stack);
int isEmpty	(iLinkedList *stack);
int size	(iLinkedList *stack);
void show	(iLinkedList *stack);
void release(iLinkedList *stack);

void init(iLinkedList *stack) {
	stack->top= NULL;
	stack->size = 0;
}

int push(iLinkedList *stack, int data) {
	No *novoNo = (No*) malloc(sizeof(No));
	if (novoNo==NULL) return -1;
	novoNo->data = data;
	novoNo->next = stack->top;
	stack->top = novoNo;
	stack->size++;
	return 1;
}

int pop(iLinkedList *stack) {
	if (!isEmpty(stack)) {
		No *aux;
		aux = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		int valor = aux->data;
		free(aux);
		return valor;
	} else
		return -1;
}

int top(iLinkedList *stack) {
	if (!isEmpty(stack))
		return stack->top->data;
	else
		return -1;
}

int isEmpty(iLinkedList *stack) {
	return stack->size==0;
}

int size(iLinkedList *stack) {
	return stack->size;
}

void show(iLinkedList *stack) {
	No *aux = stack->top;
	while (aux!=NULL) {
		printf("%d\n",aux->data);
		aux = aux->next;
	}
}

void release(iLinkedList *stack) {
	if (!isEmpty(stack)) {
		No *aux;
		do {
			aux = stack->top;
			stack->top = stack->top->next;
			free(aux);
		} while (stack->top!=NULL);
		stack->size=0;
	}
}

#endif /* PILHA_IDSTACK_H_ */
