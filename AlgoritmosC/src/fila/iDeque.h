/*
 * iDeque.h
 *
 *  Created on: 11 de jul de 2016
 *      Author: joaopaulodelgadopreti
 *
 *  Um deque é um conjunto de itens a partir do qual podem ser eliminados e inseridos
 *  itens em ambas as extremidades. Chame as duas extremidades de um deque esq e dir.
 *  Como  um  deque  pode  ser  representado  como  um  vetor  em  C? Escreva  quatro
 *  funções em C, RemDir, RemEsq, InsDir, InsEsq, para remover e inserir elementos nas
 *  extremidades esquerda e direita de um deque.
 *  Certifique-se de que as funções funcionem corretamente para o deque vazio e detectem
 *  o estouro e o underflow (tentativa de remoção quando a fila está vazia).
 *
 */

#ifndef FILA_IDEQUE_H_
#define FILA_IDEQUE_H_

#define SIZE 100

typedef struct iDeque {
    int elements[SIZE];
    int front;
    int back;
    int size;
    int id;
}iDeque;

void init(iDeque *deque, int id);
void enqueue(iDeque *deque, int element); //insere no final
void push(iDeque *deque, int element); //insere no fim
void addFront(iDeque *deque, int element); //insere no inicio
int dequeue(iDeque *deque); //remove do início
int pop(iDeque *deque); //remove do fim
int front(iDeque *deque);
int back(iDeque *deque);
int isEmpty(iDeque *deque);
int isFull(iDeque *deque);
int size(iDeque *deque);
int capacity(iDeque *deque);
void show(iDeque *deque);
int get(iDeque *deque, int i);

void init(iDeque *deque, int id) {
	deque->front=deque->back=deque->size=0;
	deque->id = id;
}

void enqueue(iDeque *deque, int element) {
	if (!isFull(deque)) {
		deque->elements[deque->back] = element;
		deque->back=(deque->back+1==SIZE)?0:deque->back+1;
		deque->size++;
	} else
		printf("Deque Overflow!\n");
}

void push(iDeque *deque, int element) {
	enqueue(deque,element);
}

void addFront(iDeque *deque, int element) {
	if (!isFull(deque)) {
		deque->front = (deque->front==0)?SIZE-1:deque->front-1;
		deque->elements[deque->front] = element;
		deque->size++;
	} else
		printf("Deque Overflow!\n");
}

int dequeue(iDeque *deque) {
	if (!isEmpty(deque)) {
		int aux = deque->elements[deque->front];
		deque->front=(deque->front+1==SIZE)?0:deque->front+1;
		deque->size--;
		return aux;
	} else {
		printf("Deque Underflow!\n");
		return -1;
	}
}

int pop(iDeque *deque) {
	if (!isEmpty(deque)) {
		deque->back=(deque->back==0)?SIZE-1:deque->back-1;;
		deque->size--;
		return deque->elements[deque->back];
	} else {
		printf("Deque Underflow!\n");
		return -1;
	}
}

int front(iDeque *deque) {
	return deque->elements[deque->front];
}

int back(iDeque *deque) {
	int aux = (deque->back==0)?SIZE-1:deque->back-1;
	return deque->elements[aux];
}

int isEmpty(iDeque *deque) {
	return deque->size == 0;
}

int isFull(iDeque *deque) {
	return deque->size == SIZE;
}

int size(iDeque *deque) {
	return deque->size;
}

int capacity(iDeque *deque) {
	return SIZE;
}

void show(iDeque *deque) {
	while (!isEmpty(deque))
		printf("%d ",dequeue(deque));
	printf("\n");
}

int get(iDeque *deque, int i) {
	if (i > SIZE-1) {
		printf("Deque out of index!\n");
		return -1;
	} else {
		int pos = (deque->front+i<SIZE)?deque->front+i:i-(SIZE-deque->front);
		return deque->elements[pos];
	}
}

#endif /* FILA_IDEQUE_H_ */
