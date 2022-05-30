#include<stdio.h>

#define DIMENSION 2
typedef struct Node {
	int point[DIMENSION];
	struct Node *left, *right; 
}Node;
typedef Node* KDTree;

void init_KDTree(KDTree* tree);
void insert(KDTree* tree, int point[]);
unsigned search(KDTree tree, int point[]);
void traverse(KDTree tree);
void deleteNode(KDTree* tree, int point[]);

