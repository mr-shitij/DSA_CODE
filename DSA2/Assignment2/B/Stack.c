#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

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

void push(StackList *list, void *data) { // Insert At First
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

void traverse(StackList list, void (*display_list)(void *)) {
	StackNode *point = list;
	while(point != NULL) {
		display_list(point->data);
		point = point->next;
	}
}

void* peek(StackList list) {
	if(list == NULL)
		return NULL;
	return list->data;
}
