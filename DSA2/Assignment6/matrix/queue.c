#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

void init_queue(Queue *queue, int size) {
	queue->size = size;
	queue->rear = queue->frount = -1;
	queue->data = calloc(queue->size, sizeof(int));
}

void enqueue(Queue *queue, int data) {
	if(queue->rear == queue->size - 1)
		printf("\n Queue is full ..!!");
	else {
		if(queue->frount == -1)
			queue->frount  = 0;
		queue->rear++;
		queue->data[queue->rear] = data;
	}
}

int dequeue(Queue *queue) {
	if(queue->frount == -1) {
		printf("\n Queue is empty ..!!");
		return -1;
	}
	else {
		int data = queue->data[queue->frount++];
		if(queue->frount > queue->rear)
			queue->frount = queue->rear = -1;
		return data;
	}
}

int isEmptyQueue(Queue *queue) {
	if(queue->frount == -1)
		return 1;
	return 0;
}

