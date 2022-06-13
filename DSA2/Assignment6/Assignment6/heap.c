#include "heap.h"
#include<stdlib.h>
#include <limits.h>
#include<stdio.h>

#define min(a,b) (a)<(b)?(a):b

void init_heap(heap* h,int size);
void insert_heap(heap *h,edge data);
void delete_heap(heap* h);

void swap(int a,int b,edge *arr){
    edge temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void heapifyup(heap* h){
     int i=h->rear;
     int parent=(i-1)/2;
     while(h->arr[parent].w>h->arr[i].w){
         swap(i,parent,h->arr);
         i=parent;
         parent=(i-1)/2;
     }
    return;
}

void init_heap(heap *h,int size){
    h->size=size;
    h->arr=(edge*)malloc(sizeof(edge)*h->size);
    h->rear=-1;
    return;
}

void insert_heap(heap *h,edge data){
   if(h->rear==h->size-1) return;
   h->arr[++h->rear]=data;
   heapifyup(h);
   return;
}

void heapifydown(heap* h){
    int i=0;
    while(1){
        int left=i*2+1;
        int right=i*2+2;
        int mini=h->arr[i].w;
        if(left<=h->rear){
            mini=min(mini,h->arr[left].w);
        }
        if(right<=h->rear)
           mini=min(mini,h->arr[right].w);


        if(mini==h->arr[i].w)
           return;
        else if(left<=h->rear && mini==h->arr[left].w){
            swap(i,left,h->arr);
            i=left;
        }
        else{
            swap(i,right,h->arr);
            i=right;
        }
    }
}

void delete_heap(heap* h){
    if(h->rear==-1) return;
    edge ele=h->arr[0];
    swap(0,h->rear,h->arr);
    h->rear--;
    heapifydown(h);
}

int isempty(heap* h){
    if(h->rear==-1) return 1;
    return 0;
}

