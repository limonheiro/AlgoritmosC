/*
 * iDStack.h
 *
 *  Created on: 6 de out de 2016
 *      Author: joaopaulodelgadopreti
 */

#ifndef FILA_IDQUEUE_H_
#define FILA_IDQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int data;
    struct No *next;
}No;

typedef struct iDQueue {
    No *first;
    No *last;
    int size;
}iDQueue;

void init	(iDQueue *queue);
int enqueue	(iDQueue *queue, int data);
int dequeue	(iDQueue *queue);
int peek	(iDQueue *queue);
int isEmpty	(iDQueue *queue);
int size	(iDQueue *queue);
void show	(iDQueue *queue);
void release(iDQueue *queue);

void init(iDQueue *queue) {
	queue->first=queue->last=NULL;
	queue->size = 0;
}

int enqueue(iDQueue *queue, int data) {
	No *novoNo = (No*) malloc(sizeof(No));
	if (novoNo==NULL) return -1;
	novoNo->data = data;

	if (isEmpty(queue)) {
		queue->first = novoNo;
		queue->last = novoNo;
	} else {
		queue->last->next = novoNo;
		queue->last = novoNo;
	}

	queue->size++;
	return 1;
}

int dequeue(iDQueue *queue) {
	if (isEmpty(queue)) return -1;
	int valor = queue->first->data;

	if (queue->first==queue->last) {
		free(queue->first);
		queue->first=queue->last=NULL;
	} else {
		No *aux;
		aux = queue->first;
		queue->first = queue->first->next;
		free(aux);
	}

	queue->size--;
	return valor;

}

int peek(iDQueue *queue) {
	if (!isEmpty(queue))
		return queue->first->data;
	else
		return -1;
}

int isEmpty(iDQueue *queue) {
	return queue->size==0;
}

int size(iDQueue *queue) {
	return queue->size;
}

void show(iDQueue *queue) {
	No *aux = queue->first;
	while (aux!=NULL) {
		printf("%d\n",aux->data);
		aux = aux->next;
	}
}

void release(iDQueue *queue) {
	if (!isEmpty(queue)) {
		No *aux;
		do {
			aux = queue->first;
			queue->first = queue->first->next;
			free(aux);
		} while (queue->first!=NULL);
		queue->size=0;
	}
}

#endif /* FILA_IDQUEUE_H_ */
