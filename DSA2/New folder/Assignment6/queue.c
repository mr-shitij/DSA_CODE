#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

void init_q(queue *q, int n)
{
	q->arr=(int *)malloc(sizeof(int)*n);
	q->front=q->rear=-1;
}

void enqueue(queue *q, int n)
{
	if(q->front==-1)
	{
		q->front++;
		q->rear++;
		q->arr[q->front]=n;
		return ;
	}
	q->rear++;
	q->arr[q->rear]=n;
	return ;
}

int dequeue(queue *q)
{
	int temp=q->arr[q->front];
	q->front++;
	return temp;
}

int is_empty(queue q)
{
	return q.front>q.rear;
}

void delete_queue(queue *q)
{
	free(q->arr);
	q->arr=NULL;
	return ;
}
