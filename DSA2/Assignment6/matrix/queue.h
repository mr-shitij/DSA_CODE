#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
	int* data;
	int rear, frount, size;
}Queue;

void (Queue* queue, int size);
void enqueue(Queue *list, int data);
int dequeue(Queue *list);

