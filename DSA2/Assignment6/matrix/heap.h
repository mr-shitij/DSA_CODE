#include<stdio.h>
#include<stdlib.h>
#ifndef _EDGES_
	#include"edges.h"
#endif

typedef struct Heap {
	Edges* array;
	int rear;
	int size;
} Heap;

void init_heap(Heap* heap, int size);
void insert_heap(Heap *heap, Edges data);
Edges* delete_heap(Heap *heap);
int isEmptyHeap(Heap *heap);

