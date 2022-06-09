#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode {
	struct StackNode* next;
	int data;
}StackNode;
typedef StackNode* StackList;

void initStack(StackList *list);

// To work as a stack
void push(StackList *list, int data);
int pop(StackList *list);

int peek(StackList list);
int isEmptyStack(StackList list);
