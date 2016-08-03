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
    int size;
    int rear;
    int id;
}iDeque;

void init(iDeque *deque, int id);
void enqueue(iDeque *deque, int element); //insere no início
int dequeue(iDeque *deque); //remove do início
void push(iDeque *deque, int element); //insere no fim
int pop(iDeque *deque); //remove do fim
int peek(iDeque *deque);
int top(iDeque *deque);
int isEmpty(iDeque *deque);
int isFull(iDeque *deque);
int size(iDeque *deque);
int capacity(iDeque *deque);
void show(iDeque *deque);
int get(iDeque *deque, int i);

#endif /* FILA_IDEQUE_H_ */
