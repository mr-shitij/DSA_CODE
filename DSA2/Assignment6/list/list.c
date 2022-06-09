#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node *getNewNode() {
	Node *newNode = (Node *)malloc(sizeof(Node *));
	if (newNode == NULL) {
		printf("\n Memory is full ..!!");
		return NULL;
	}
	newNode->next = NULL;
	return newNode;
}

void insertAtFirst(List *list, int node_id, int weight) {
	Node *newNode = getNewNode();
	newNode->weight = weight;
	newNode->node_id = node_id;
	if (list == NULL) {
		*list = newNode;
		return;
	}
	newNode->next = *list;
	*list = newNode;
}

void traverse(List list) {
	Node *start = list;
	while (start != NULL) {
		printf(" { %d : %d } ", start->node_id, start->weight);
		start = start->next;
	}
}

int is_contains(List list, int node) {
	Node *start = list;
	while (start != NULL) {
		if(start->node_id == node)
			return 1;	
		start = start->next;
	}
	return 0;
}

int get_size_list(List list) {
	int size = 0;
	Node *start = list;
	while (start != NULL) {
		size++;		
		start = start->next;
	}
	return size;
}
