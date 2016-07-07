/*
 * iQueue.h
 *
 *  Created on: 12 de jun de 2016
 *      Author: joaopaulodelgadopreti
 */

#ifndef FILA_IQUEUE_H_
#define FILA_IQUEUE_H_

#include <stdio.h>

#define SIZE 100

typedef struct iQueue {
    int elements[SIZE];
    int begin; //For a circular queue
    int size;
    int end;
    int id;
}iQueue;

void init(iQueue *queue, int id);
void enqueue(iQueue *queue, int element);
int dequeue(iQueue *queue);
int peek(iQueue *queue);
int isEmpty(iQueue *queue);
int isFull(iQueue *queue);
int size(iQueue *queue);
int capacity(iQueue *queue);
void show(iQueue *queue);

void init(iQueue *queue, int id) {
	queue->begin=queue->end=queue->size=0;
	queue->id = id;
}

void enqueue(iQueue *queue, int element) {
	if (!isFull(queue)) {
		queue->elements[queue->end] = element;
		queue->end=(queue->end+1==SIZE)?0:queue->end+1;
		queue->size++;
	} else
		printf("Queue Overflow!\n");
}

int dequeue(iQueue *queue) {
	if (!isEmpty(queue)) {
		int aux = queue->elements[queue->begin];
		queue->begin=(queue->begin+1==SIZE)?0:queue->begin+1;
		queue->size--;
		return aux;
	} else {
		printf("Queue Underflow!\n");
		return -1;
	}
}

int peek(iQueue *queue) {
	return queue->elements[queue->begin];
}

int isEmpty(iQueue *queue) {
	return queue->size == 0;
}

int isFull(iQueue *queue) {
	return queue->size == SIZE;
}

int size(iQueue *queue) {
	return queue->size;
}

int capacity(iQueue *queue) {
	return SIZE;
}

void show(iQueue *queue) {
	while (!isEmpty(queue))
		printf("%d ",dequeue(queue));
	printf("\n");
}

#endif /* FILA_IQUEUE_H_ */


