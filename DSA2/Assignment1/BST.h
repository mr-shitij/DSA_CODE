#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	int MIS;
	char *name;
}Node;
typedef Node* BST;


void initBST(BST *tree);

void add_node(BST *tree, int data);

void insertNode(BST *tree, int data);
void removeNode();
void search(BST tree);

void preorder(BST tree);
void postorder(BST tree);
void inorder(BST tree);
void Display_Level();
void destoryTree();
