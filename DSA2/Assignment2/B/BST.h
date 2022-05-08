#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int MIS;
}Node;
typedef Node* BST;

void initBST(BST *tree);

Node* generateFromTree(int data[], int start, int end);

void insertNode(BST *tree, int data);

void preorder(BST tree);
void postorder(BST tree);
void inorder(BST tree);

