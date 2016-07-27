#ifndef FILA_PROCESSOQUEUE_H_
#define FILA_PROCESSOQUEUE_H_

#include <stdio.h>

#define SIZE 100

typedef struct processo {
    int id;
    int tempoDuracao;
    int tempoProcessado;
    int numAlocacoes;
}processo;

typedef struct processoQueue {
    processo elements[SIZE];
    int begin; //For a circular queue
    int size;
    int end;
    int id;
}processoQueue;

void init(processoQueue *queue, int id);
void enqueue(processoQueue *queue, processo element);
processo dequeue(processoQueue *queue);
processo peek(processoQueue *queue);
int isEmpty(processoQueue *queue);
int isFull(processoQueue *queue);
int size(processoQueue *queue);
int capacity(processoQueue *queue);
void show(processoQueue *queue);
processo get(processoQueue *queue, int i);

void init(processoQueue *queue, int id) {
	queue->begin=queue->end=queue->size=0;
	queue->id = id;
}

void enqueue(processoQueue *queue, processo element) {
	if (!isFull(queue)) {
		queue->elements[queue->end] = element;
		queue->end=(queue->end+1==SIZE)?0:queue->end+1;
		queue->size++;
	} else
		printf("Queue Overflow!\n");
}

processo dequeue(processoQueue *queue) {
	processo aux;
	if (!isEmpty(queue)) {
		aux = queue->elements[queue->begin];
		queue->begin=(queue->begin+1==SIZE)?0:queue->begin+1;
		queue->size--;
	} else {
		printf("Queue Underflow!\n");
	}
	return aux;
}

processo peek(processoQueue *queue) {
	return queue->elements[queue->begin];
}

int isEmpty(processoQueue *queue) {
	return queue->size == 0;
}

int isFull(processoQueue *queue) {
	return queue->size == SIZE;
}

int size(processoQueue *queue) {
	return queue->size;
}

int capacity(processoQueue *queue) {
	return SIZE;
}

void show(processoQueue *queue) {
	while (!isEmpty(queue)) {
		processo proc = dequeue(queue);
		printf("(%d,%d) ",proc.id, proc.tempoDuracao);
	}
	printf("\n");
}

processo get(processoQueue *queue, int i) {
	return (queue->elements[i]);
}

#endif /* FILA_PROCESSOQUEUE_H_ */


