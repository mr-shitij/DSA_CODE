#include "linkedlist.h"
#include<stdlib.h>

void initll(ll** node){
    *node=NULL;
}

void insertll(ll** node,int v,int w){
    ll* newnode=malloc(sizeof(ll));
    if(!newnode) return;
    newnode->vertex=v;
    newnode->weight=w;
    newnode->next=NULL;
    if(*node==NULL){
        *node=newnode;
        return;
    }
    ll* head=*node;
    while(head->next)
       head=head->next;
    head->next=newnode;
    return;
}

