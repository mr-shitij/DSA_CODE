#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void init_stack(Stack* stack, int size) {
	stack->size = size;
	stack->top = -1;
	stack->data = calloc(stack->size, sizeof(int));
}

void push(Stack *stack, int data) {
	if(stack->top == stack->size - 1)
		printf("\n Stack is full ..!!");
	else {
		stack->top++;
		stack->data[stack->top] = data;
	}
}

int pop(Stack *stack) {
	if(stack->top == -1) {
		printf("\n Stack is empty ..!!");
		return -1;
	}
	else {
		int data = stack->data[stack->top--];
		return data;
	}
}

int isEmptyStack(Stack *stack) {
	if(stack->top == -1)
		return 1;
	return 0;
}

