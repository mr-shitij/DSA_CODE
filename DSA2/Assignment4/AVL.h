#include<stdio.h>
#include<stdlib.h>

#define NAME_SIZE 20

typedef struct Node {
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int MIS;
	char name[NAME_SIZE];
	int balanceFactor;
}Node;
typedef Node* AVL;

void initAVL(AVL *tree);
void insertNode(AVL *tree, int data, char name[]);
void removeNode();
void traverse(AVL tree);
void destoryTree();

