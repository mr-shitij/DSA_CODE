#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#include"BHE.h"

void init_heap(Heap* heap, int size) {
	heap->arr = malloc(sizeof(Heap) * size);
	heap->size = size;
	heap->rear = -1;
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void heapify(Heap* heap) {
	int i = heap->rear;
	int p_i = (i - 1) / 2;
	
	while (p_i >= 0 && heap->arr[i] > heap->arr[p_i]) {
		swap(&(heap->arr[i]), &(heap->arr[p_i]));
		i = p_i;
		p_i = (i - 1) / 2;
	}
}

void insert_heap(Heap* heap, int data) {
	if (heap->rear == heap->size - 1) {
		printf("Heap full");
		return;
	}

	heap->arr[++heap->rear] = data;
	heapify(heap);
}

void heapify_td(Heap* heap) {
    int i = 0;
    int c_i_l = 2 * i + 1;
    int c_i_r = 2 * i + 2;

    while (c_i_l <= heap->rear) {
        if (heap->arr[i] < heap->arr[c_i_l]) {
            swap(&(heap->arr[i]), &(heap->arr[c_i_l]));
        }
        i = c_i_l;
        c_i_l = 2 * i + 1;
    }

    i = 0;
    while (c_i_r <= heap->rear) {
        if (heap->arr[i] < heap->arr[c_i_r]) {
            swap(&(heap->arr[i]), &(heap->arr[c_i_r]));
        }
        i = c_i_r;
        c_i_r = 2 * i + 2;
    }
}

void delete_heap(Heap* heap) {
	if (heap->rear == -1)
		return;

	int ele = heap->arr[heap->rear];
	swap(&(heap->arr[heap->rear]), &(heap->arr[0]));
	heap->rear--;

	heapify_td(heap);
}

void heap_sort(Heap* heap) {
    while (heap->rear != -1) {
        delete_heap(heap);
    }

    for (int i = 0; i < heap->size; i++) {
        heap->rear++;
    }
}

void get_data_from_file(char file_name[], Heap *heap) {
	int data;
	FILE* fp = fopen(file_name, "r");
	while (fscanf(fp, "%d\n", &data) == 1) {
		insert_heap(heap, data);
	}

	fclose(fp);
}

void build_heap(Heap* heap, char file_name[]) {
    get_data_from_file(file_name, heap);
}

void traverse(Heap heap) {
	for(int i = 0; i < heap.rear; i++) {
		printf("%d\n", heap.arr[i]);
	}
}

