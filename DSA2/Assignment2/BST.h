#include <stdlib.h>
#include <stdlib.h>

#define SIZE_TREE 100
typedef struct Node {
	int *array;
	int size;
	char balanceFactor;
}Node;
typedef Node* BST;

void init_bst(BST *tree);
void insert_bst(BST *tree, int data);
void recursive_traverse(BST tree, int index);
int isComplete(BST tree);


