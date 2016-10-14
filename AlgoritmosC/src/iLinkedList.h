/*
 * iDStack.h
 *
 *  Created on: 6 de out de 2016
 *      Author: joaopaulodelgadopreti
 */

#ifndef LINKEDLIST_LINKEDLIST_H_
#define LINKEDLIST_LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int data;
    struct No *next;
}No;

typedef struct iLinkedList {
    No *first;
    No *last;
    int size;
}iLinkedList;

void init	(iLinkedList *list);
int addFirst(iLinkedList *list, int data);
int addLast	(iLinkedList *list, int data);
int addPos	(iLinkedList *list, int pos, int data);
int addArray(iLinkedList *list, int *array, int size);
int add		(iLinkedList *list, int data);
int set		(iLinkedList *list, int pos, int data);
int get		(iLinkedList *list, int pos);
No* getNo	(iLinkedList *list, int pos);
int remFirst(iLinkedList *list);
int remLast	(iLinkedList *list);
int remPos	(iLinkedList *list, int pos);
int index	(iLinkedList *list, int data);
int isEmpty	(iLinkedList *list);
void toArray(iLinkedList *list, int *array, int size);
int size	(iLinkedList *list);
void show	(iLinkedList *list);
void release(iLinkedList *list);

void init(iLinkedList *list) {
	list->first = list->last = NULL;
	list->size = 0;
}

int addFirst(iLinkedList *list, int data) {
	No *no = (No*)malloc(sizeof(No));
	if (no == NULL) return 0;
	no->data = data;

	if (isEmpty(list)) {
		list->first = list->last= no;
	} else {
		no->next = list->first;
		list->first = no;
	}
	list->size++;
	return 1;
}

int addLast(iLinkedList *list, int data) {
	No *no = (No*)malloc(sizeof(No));
	if (no == NULL) return 0;
	no->data = data;

	if (isEmpty(list)) {
		list->first = list->last= no;
	} else {
		list->last->next = no;
		list->last = no;
	}
	list->size++;
	return 1;
}

int addPos(iLinkedList *list, int pos, int data) {
	if (pos<=0) 		 return addFirst(list, data);
	if (pos>=size(list)) return addLast (list, data);

	No *no = (No*)malloc(sizeof(No));
	if (no == NULL) return 0;
	no->data = data;

	No *noAnt = getNo(list, pos-1);
	no->next = noAnt->next;
	noAnt->next = no;

	return 1;
}

int addArray(iLinkedList *list, int *array, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count+=addLast(list, array[i]);
	}
	return count;
}

int add(iLinkedList *list, int data) {
	if (isEmpty(list) || data<=list->first->data) return addFirst(list,data);
	if (data>=list->last->data) 				  return addLast(list,data);

	No *no = (No*)malloc(sizeof(No));
	if (no == NULL) return 0;
	no->data = data;

	No *aux;
	for (aux = list->first; aux!=NULL && data<aux->next->data; aux=aux->next);
	no->next = aux->next;
	aux->next = no;

	return 1;
}

int set(iLinkedList *list, int pos, int data) {
	if (!isEmpty(list) && pos>=0 && pos<size(list)) {
		getNo(list,pos)->data = data;
		return 1;
	} else
		return -1;
}

int get(iLinkedList *list, int pos) {
	if (!isEmpty(list) && pos>=0 && pos<size(list))
		return getNo(list,pos)->data;
	else
		return -1;
}

No* getNo(iLinkedList *list, int pos) {
	int count = -1;
	No * aux;
	for (aux = list->first; aux!=NULL; aux = aux->next,++count) {
		if (pos == count) return aux;
	}
	return NULL;
}

int remFirst(iLinkedList *list) {
	if (isEmpty(list)) return -1;

	No *aux = list->first;
	list->first = list->first->next;
	int data = aux->data;
	free(aux);
	list->size--;
	return data;
}

int remLast(iLinkedList *list) {
	if (isEmpty(list)) return -1;

	int data = list->last->data;

	if (list->first==list->last) {
		free(list->first);
		list->first=list->last=NULL;
	} else {
		free(list->last);
		list->last = getNo(list,size(list)-2);
	}
	list->size--;
	return data;
}

int remPos(iLinkedList *list, int pos) {
	if (!isEmpty(list) && pos>=0 && pos<size(list)) {
		if (pos==0 && size(list)==1) {
			int data = list->first->data;
			free(list->first);
			list->first=list->last=NULL;
			list->size = 0;
		} else {
			No *noAnt = getNo(list,pos-1);
			int data = noAnt->next->data;
			No *noRem = noAnt->next;
			noAnt->next = noRem->next;
			free(noRem);
			return data;
		}
	}

	return -1;
}

int index(iLinkedList *list, int data) {
	int count = -1;
	for (No *aux = list->first; aux!=NULL; aux = aux->next,++count) {
		if (aux->data == data) return count;
	}
	return -1;
}

int isEmpty(iLinkedList *list) {
	return list->size==0;
}
void toArray(iLinkedList *list, int *array, int size) {
	if (size<size(list))
		printf("Warning: not all elements in the list will be transfered to the array. Array size is smaller than the list size.");

	No *aux = list->first;
	for (int i = 0; i < size; i++,aux=aux->next) {
		array[i] = aux->data;
	}
}

int size(iLinkedList *list) {
	return list->size;
}

void show(iLinkedList *list) {
	No *aux = list->first;
	while (aux!=NULL) {
		printf("%d\n",aux->data);
		aux = aux->next;
	}
}

void release(iLinkedList *list) {
	if (!isEmpty(list)) {
		No *aux;
		do {
			aux = list->first;
			list->first = list->first->next;
			free(aux);
		} while (list->first!=NULL);
		list->size=0;
	}
}


#endif /* LINKEDLIST_LINKEDLIST_H_ */
