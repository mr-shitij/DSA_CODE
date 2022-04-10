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

/*
int pop(List *list) { // Remove From Last
	if(*list == NULL) {
		return 1; // stack underflow
	} else {
		ListNode *lastNode = *list;
		ListNode *secondLastNode = NULL;
		while(lastNode->next != NULL) {
			secondLastNode = lastNode;
			lastNode = lastNode->next;
		}
		if(secondLastNode != NULL) { // If true it means we have at least two nodes else only one node
			secondLastNode->next = NULL;			
		}
		free(lastNode);
	}
	return 0;
}
*/
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

/*
void display(void *data) {
	printf("\n %d", *((int*)data));
}

void main() {
	List first;
	initList(&first);
	
	int* aa = malloc(sizeof(int));
	*aa = 10;
	void* a = aa;

	int* bb = malloc(sizeof(int));
	*bb = 20;
	void* b = bb;
	
//	enqueue(&first, &a);
//	enqueue(&first, &b);

	push(&first, &a);
	push(&first, &b);

	traverse(first, display);

//	dequeue(&first);
	pop(&first);

	traverse(first, display);

//	dequeue(&first);
//	printf("\n DEQ : %d", dequeue(&first));

	pop(&first);
	printf("\n DEQ : %d", pop(&first));

	traverse(first, display);

}
*/
