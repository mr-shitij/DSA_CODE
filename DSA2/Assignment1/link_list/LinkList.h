#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	struct ListNode* next;
	void* data;
}ListNode;
typedef ListNode* List;

void initList(List *list);

// To work as a stack
void push(List *list, void *data);
int pop(List *list);

// To work as a queue
void enqueue(List *list, void *data);
int dequeue(List *list);

void traverse(List list, void (*display_list)(void *));
void* peek(List list);

