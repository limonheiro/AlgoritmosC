#ifndef FILA_PROCESSOIOQUEUE_H_
#define FILA_PROCESSOIOQUEUE_H_

#include <stdio.h>

#define SIZE 100

typedef struct processoIO {
    int id;
    int processamento[SIZE];
    int io[SIZE];
    int numAlocacoes;
}processoIO;

typedef struct processoIOQueue {
    processoIO elements[SIZE];
    int begin; //For a circular queue
    int size;
    int end;
    int id;
}processoIOQueue;

void init(processoIOQueue *queue, int id);
void enqueue(processoIOQueue *queue, processoIO element);
processoIO dequeue(processoIOQueue *queue);
processoIO peek(processoIOQueue *queue);
int isEmpty(processoIOQueue *queue);
int isFull(processoIOQueue *queue);
int size(processoIOQueue *queue);
int capacity(processoIOQueue *queue);
void show(processoIOQueue *queue);
processoIO *get(processoIOQueue *queue, int i);

void init(processoIOQueue *queue, int id) {
	queue->begin=queue->end=queue->size=0;
	queue->id = id;
}

void enqueue(processoIOQueue *queue, processoIO element) {
	if (!isFull(queue)) {
		queue->elements[queue->end] = element;
		queue->end=(queue->end+1==SIZE)?0:queue->end+1;
		queue->size++;
	} else
		printf("Queue Overflow!\n");
}

processoIO dequeue(processoIOQueue *queue) {
	processoIO aux;
	if (!isEmpty(queue)) {
		aux = queue->elements[queue->begin];
		queue->begin=(queue->begin+1==SIZE)?0:queue->begin+1;
		queue->size--;
	} else {
		printf("Queue Underflow!\n");
	}
	return aux;
}

processoIO peek(processoIOQueue *queue) {
	return queue->elements[queue->begin];
}

int isEmpty(processoIOQueue *queue) {
	return queue->size == 0;
}

int isFull(processoIOQueue *queue) {
	return queue->size == SIZE;
}

int size(processoIOQueue *queue) {
	return queue->size;
}

int capacity(processoIOQueue *queue) {
	return SIZE;
}

void show(processoIOQueue *queue) {
	while (!isEmpty(queue)) {
		processoIO proc = dequeue(queue);
		printf("(%d)\n",proc.id);
	}
	printf("\n");
}

processoIO *get(processoIOQueue *queue, int i) {
	if (i > SIZE-1) {
		printf("Queue out of index!\n");
		return NULL;
	} else {
		int pos = (queue->begin+i<SIZE)?queue->begin+i:i-(SIZE-queue->begin);
		return &(queue->elements[pos]);
	}
}

#endif /* FILA_PROCESSOIOQUEUE_H_ */


