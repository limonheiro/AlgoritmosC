/**************************************************************************
 * Biblioteca de Pilha		                                              *
 *                                                                        *
 * Biblioteca com operações de pilha							 		  *
 * Data: 30/05/2016			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/

#ifndef SDSTACK_H_
#define SDSTACK_H_

#define SIZE 100

typedef struct sdStack {
    char *elements[SIZE];
    int top1=-2;
    int top2=-2;
}sdStack;

void init(sdStack *stack, int idStack);
void push(sdStack *stack, char *element, int idStack);
char* pop(sdStack *stack, int idStack);
char* top(sdStack *stack, int idStack);
int isEmpty(sdStack *stack, int idStack);
int isFull(sdStack *stack);
int size(sdStack *stack, int idStack);
int capacity(sdStack *stack, int idStack);
void show(sdStack *stack, int idStack);

void init(sdStack *stack, int idStack) {
	if (idStack==1) {
		stack->top1 = -1;
		if (stack->top2==-2) stack->top2=SIZE;
	} else {
		stack->top2 = SIZE;
		if (stack->top1==-2) stack->top1=-1;
	}
}

void push(sdStack *stack, char *element, int idStack) {
    if (!isFull(stack)) {
    	if (idStack==1) {
    		stack->top1++;
    		stack->elements[stack->top1]=element;
    	} else {
    		stack->top2--;
    		stack->elements[stack->top2]=element;
    	}
    } else
        printf("Push not allowed: stack is full.\n");
}

char* pop(sdStack *stack, int idStack) {
	if (idStack==1) {
		if (!isEmpty(stack, 1)) {
			stack->top1--;
			return stack->elements[stack->top1+1];
		} else {
			printf("Pop not allowed: stack is empty.\n");
			return "";
		}
	} else {
		if (!isEmpty(stack, idStack)) {
			stack->top2++;
			return stack->elements[stack->top2-1];
		} else {
			printf("Pop not allowed: stack is empty.\n");
			return "";
		}
	}
}

char* top(sdStack *stack, int idStack) {
	if (idStack==1)
		return (isEmpty(stack,1))?" ":stack->elements[stack->top1];
	else
		return (isEmpty(stack,idStack))?" ":stack->elements[stack->top2];
}

int isEmpty(sdStack *stack, int idStack) {
	if (idStack==1)
		return stack->top1==-1;
	else
		return stack->top2==SIZE;
}

int isFull(sdStack *stack) {
    return stack->top1+1==stack->top2;
}

int size(sdStack *stack, int idStack) {
	if (idStack==1)
		return stack->top1+1;
	else
		return SIZE-stack->top2;
}

int capacity(sdStack *stack, int idStack) {
	if (idStack==1)
		return size(stack, 1) + (stack->top2-stack->top1+1);
	else {
		return size(stack, idStack) + (stack->top2-stack->top1+1);
	}
}

void show(sdStack *stack, int idStack) {
	if (idStack==1)
		while (!isEmpty(stack,1)) {
			printf("%s", pop(stack,1));
		}
	else
		while (!isEmpty(stack,idStack)) {
			printf("%s", pop(stack,idStack));
		}
}

#endif /* SDSTACK_H_ */
