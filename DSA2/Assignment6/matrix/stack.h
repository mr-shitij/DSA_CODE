#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
	int* data;
	int top;
	int size;
}Stack;

void init_stack(Stack* stack, int size);
void push(Stack *list, int data);
int pop(Stack *list);
int isEmptyStack(Stack *stack);

