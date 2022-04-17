#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"

void initList(List *list) {
	*list = NULL;
}

void enqueue(List *list, void *data) { // Insert At Last
	ListNode* newNode = malloc(sizeof(ListNode));	
	newNode->next = NULL;
	newNode->data = data;
	
	if(newNode == NULL) {
		return;
	}

	if(*list  == NULL) {
		*list = newNode;
	} else {
		ListNode *lastNode = *list;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
}

int dequeue(List *list) { // Remove From First
	if(*list == NULL) {
		return 1; // queue underflow
	} else {
		ListNode* secondNode = NULL;
		
		if((*list)->next != NULL)
			secondNode = (*list)->next;
		
		free(*list);
		*list = secondNode;		
	}
	return 0;

}

int pop(List *list) { // Remove From First
	return dequeue(list);
}

void push(List *list, void *data) { // Insert At First
	ListNode* newNode = malloc(sizeof(ListNode));	
	newNode->next = NULL;
	newNode->data = data;

	if(newNode == NULL) {
		return;
	}

	if(*list == NULL) {
		*list = newNode;
	} else {
		ListNode *firstNode = *list;
		*list = newNode;
		(*list)->next = firstNode;		
	}
}

void traverse(List list, void (*display_list)(void *)) {
	ListNode *point = list;
	while(point != NULL) {
		display_list(point->data);
		point = point->next;
	}
}

void* peek(List list) {
	if(list == NULL)
		return NULL;
	return list->data;
}
