#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
	int* data;
	int rear; 
	int frount;
	int size;
}Queue;

void init_queue(Queue* queue, int size);
void enqueue(Queue *list, int data);
int dequeue(Queue *list);
int isEmptyQueue(Queue *queue);

