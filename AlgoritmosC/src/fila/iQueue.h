/*
 * iQueue.h
 *
 *  Created on: 12 de jun de 2016
 *      Author: joaopaulodelgadopreti
 */

#ifndef FILA_IQUEUE_H_
#define FILA_IQUEUE_H_

#define SIZE 100

typedef struct iQueue {
    int elements[SIZE];
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

#endif /* FILA_IQUEUE_H_ */
