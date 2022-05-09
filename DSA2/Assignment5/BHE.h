#include<stdio.h>
#include<stdlib.h>

#define NAME_SIZE 20

typedef struct Node {
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int data;
}Node;
typedef Node* BHE;

void initBHE(BHE *tree);
void insertNode(BHE *tree, int data);
void removeNode();
void traverse(BHE tree);
void destoryTree();

