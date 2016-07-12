/*
 * iQueue.h
 *
 *  Created on: 12 de jun de 2016
 *      Author: joaopaulodelgadopreti
 */

#ifndef FILA_regClienteQueue_H_
#define FILA_regClienteQueue_H_

#include <stdio.h>

#define SIZE 100

typedef struct regCliente {
	int id,tempoChegada, tempoOcuparaCaixa;
}regCliente;

typedef struct regClienteQueue {
    regCliente elements[SIZE];
    int begin; //For a circular queue
    int size;
    int end;
    int id;
}regClienteQueue;

void init(regClienteQueue *queue, int id);
void enqueue(regClienteQueue *queue, regCliente element);
regCliente dequeue(regClienteQueue *queue);
regCliente peek(regClienteQueue *queue);
int isEmpty(regClienteQueue *queue);
int isFull(regClienteQueue *queue);
int size(regClienteQueue *queue);
int capacity(regClienteQueue *queue);
void show(regClienteQueue *queue);

void init(regClienteQueue *queue, int id) {
	queue->begin=queue->end=queue->size=0;
	queue->id = id;
}

void enqueue(regClienteQueue *queue, regCliente element) {
	if (!isFull(queue)) {
		queue->elements[queue->end] = element;
		queue->end=(queue->end+1==SIZE)?0:queue->end+1;
		queue->size++;
	} else
		printf("Queue Overflow!\n");
}

regCliente dequeue(regClienteQueue *queue) {
	regCliente aux;
	if (!isEmpty(queue)) {
		aux = queue->elements[queue->begin];
		queue->begin=(queue->begin+1==SIZE)?0:queue->begin+1;
		queue->size--;
	} else {
		printf("Queue Underflow!\n");
	}
	return aux;
}

regCliente peek(regClienteQueue *queue) {
	return queue->elements[queue->begin];
}

int isEmpty(regClienteQueue *queue) {
	return queue->size == 0;
}

int isFull(regClienteQueue *queue) {
	return queue->size == SIZE;
}

int size(regClienteQueue *queue) {
	return queue->size;
}

int capacity(regClienteQueue *queue) {
	return SIZE;
}

void show(regClienteQueue *queue) {
	while (!isEmpty(queue)) {
		regCliente aux = dequeue(queue);
		printf("(id:%d tempo:%d\n) ",aux.id, aux.tempoOcuparaCaixa);
	}
}

#endif /* FILA_regClienteQueue_H_ */


