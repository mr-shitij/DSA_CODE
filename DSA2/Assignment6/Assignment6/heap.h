#ifndef __heap__
#define __heap__
#include "graph.h"

typedef struct heap{
    int size;
    edge * arr;
    int rear;
} heap;


void init_heap(heap* h,int size);
void insert_heap(heap *h,edge data);
void delete_heap(heap* h);
int isempty(heap*h);
// 
#endif