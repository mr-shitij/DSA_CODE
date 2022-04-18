#include<stdio.h>
#include<stdlib.h>

typedef struct QueueNode {
	struct QueueNode* next;
	void* data;
}QueueNode;
typedef QueueNode* QueueList;

void initQueueNode(QueueList *list);

// To work as a queue
void enqueue(QueueList *list, void *data);
int dequeue(QueueList *list);

