#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

void initQueue(QueueList *list) {
	*list = NULL;
}

void enqueue(QueueList *list, void *data) { // Insert At Last
	QueueNode* newNode = malloc(sizeof(QueueNode));	
	newNode->next = NULL;
	newNode->data = data;
	
	if(newNode == NULL) {
		return;
	}

	if(*list  == NULL) {
		*list = newNode;
	} else {
		QueueNode *lastNode = *list;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
}

int dequeue(QueueList *list) { // Remove From First
	if(*list == NULL) {
		return 1; // queue underflow
	} else {
		QueueNode* secondNode = NULL;
		
		if((*list)->next != NULL)
			secondNode = (*list)->next;
		
		free(*list);
		*list = secondNode;		
	}
	return 0;

}

