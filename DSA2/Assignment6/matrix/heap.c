// Min Heap

#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
#ifndef _EDGES_
	#include"edges.h"
#endif

void init_heap(Heap* heap, int size) {
	heap->array = malloc(sizeof(Edges) * size);
	heap->rear = -1;
	heap->size = size;
}

void heapify_bu(Heap* heap) {
	int i = heap->rear;
	int p_i = (i - 1) / 2;
	while(heap->array[i].weight < heap->array[p_i].weight) {
		Edges temp = heap->array[i];
		heap->array[i] = heap->array[p_i];
		heap->array[p_i] = temp;
	}
}

void insert_heap(Heap *heap, Edges data) {
	if(heap->rear == heap->size - 1) {
		printf("Heap Is Full ..!!\n");
		return;
	}
	++heap->rear;
	heap->array[heap->rear] = data;
	heapify_bu(heap);
}

void heapify_ub(Heap* heap) {
	int i = 0;
	int c_l = (2 * i) + 1;
	int c_r = (2 * i) + 2;
	
	while(c_l < heap->rear) {
		if(heap->array[i].weight > heap->array[c_l].weight) {
			Edges temp = heap->array[i];
			heap->array[i] = heap->array[c_l];
			heap->array[c_l] = temp;
		}
		i = c_l;
		c_l = (2 * i) + 1;
	}

	i = 0;
	while(c_r < heap->rear) {
		if(heap->array[i].weight > heap->array[c_r].weight) {
			Edges temp = heap->array[i];
			heap->array[i] = heap->array[c_r];
			heap->array[c_r] = temp;
		}
		i = c_r;
		c_r = (2 * i) + 1;
	}
	
	
}

Edges* delete_heap(Heap *heap) {
	if(heap->rear == -1) {
		printf("Heap UnderFlow ..!!\n");
		return NULL;
	}
	Edges* temp = heap->array[0];
	heap->array[0] = heap->array[heap->rear];
	heap->array[heap->rear] = temp;
	heap->rear--;
	
	heapify_ub(heap);
	return temp;
}

int isEmptyHeap(Heap *heap) {
	if(heap->rear == -1)
		return 1;
	return 0;
}

