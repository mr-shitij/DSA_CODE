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
void search(BST tree, int MIS); // to recursively search for a node with the given key.

void preorder(BST tree);
void postorderNonRecursive(BST tree);
void postorder(BST tree);
void inorder(BST tree);
void Display_Level(BST tree, int level);
void destoryTree();
