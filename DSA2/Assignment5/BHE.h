#include<stdio.h>
#include<stdlib.h>

#define MAX_RAND 10

typedef struct Heap {
	int *arr;
	int size;
	int rear;
} Heap;

void init_heap(Heap *heap, int size);
void insert_heap(Heap *heap, int data);
void delete_heap(Heap *heap);
void traverse(Heap heap);
void build_heap(Heap* heap, char file_name[]);

