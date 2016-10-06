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
}iDStack;

void init(iDStack *stack);
int push(iDStack *stack, int data);
int pop(iDStack *stack);
int top(iDStack *stack);
int isEmpty(iDStack *stack);
int size(iDStack *stack);
void show(iDStack *stack);
void release(iDStack *stack);

void init(iDStack *stack) {
	stack->top= NULL;
	stack->size = 0;
}

int push(iDStack *stack, int data) {
	No *novoNo = (No*) malloc(sizeof(No));
	if (novoNo==NULL) return -1;
	novoNo->data = data;
	novoNo->next = stack->top;
	stack->top = novoNo;
	stack->size++;
	return 1;
}

int pop(iDStack *stack) {
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

int top(iDStack *stack) {
	if (!isEmpty(stack))
		return stack->top->data;
	else
		return -1;
}

int isEmpty(iDStack *stack) {
	return stack->size==0;
}

int size(iDStack *stack) {
	return stack->size;
}

void show(iDStack *stack) {
	No *aux = stack->top;
	while (aux!=NULL) {
		printf("%d\n",aux->data);
		aux = aux->next;
	}
}

void release(iDStack *stack) {
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
