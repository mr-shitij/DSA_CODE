#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "SearchEngine.h"
#include "stack.h"

void init(stack *top){
    *top=NULL;
    return;
}

void push(stack *top, node *d){
    stack nn;
    nn=(snode*)malloc(sizeof(snode));

    if(nn){
        nn->b=d;
        if(*top==NULL){
            *top=nn;
            nn->next=NULL;
        }
        else{
            nn->next=*top;
            *top=nn;
        }
    }
    return;
}

node* pop(stack *top){
    if(isEmpty(*top)){
        return NULL;
    }
    snode *p=*top;
    node *x;
    *top=p->next;
    x=p->b;
    p->next=NULL;
    free(p);
    return x;
}

node* peek(stack top){
    if(!isEmpty(top)){
        return top->b;
    }
    else
        return NULL;
}

int isEmpty(stack top){
    if(top==NULL){
        return 1;
    }
    else
        return 0;
}
