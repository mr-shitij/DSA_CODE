#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include"stack.h"

void initStack(StackList *list) {
	*list = NULL;
}

int pop(StackList *list) { // Remove From First
	if(*list == NULL) {
		return 1; // queue underflow
	} else {
		StackNode* secondNode = NULL;
		
		if((*list)->next != NULL)
			secondNode = (*list)->next;
		
		free(*list);
		*list = secondNode;		
	}
	return 0;
}

void push(StackList *list, int data) { // Insert At First
	StackNode* newNode = malloc(sizeof(StackNode));	
	newNode->next = NULL;
	newNode->data = data;

	if(newNode == NULL) {
		return;
	}

	if(*list == NULL) {
		*list = newNode;
	} else {
		StackNode *firstNode = *list;
		*list = newNode;
		(*list)->next = firstNode;		
	}
}

int peek(StackList list) {
	if(list == NULL)
		return INT_MAX;
	return list->data;
}

int isEmpty(StackList list) {
	if(list == NULL) {
		return 0;
	}
	return 1;
}

