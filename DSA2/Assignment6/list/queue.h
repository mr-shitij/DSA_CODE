#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode {
	struct QueueNode* next;
	int data;
}QueueNode;
typedef QueueNode* QueueList;

void initQueueNode(QueueList *list);

// To work as a queue
void enqueue(QueueList *list, int data);
int dequeue(QueueList *list);

int isEmptyQueue(QueueList list);
