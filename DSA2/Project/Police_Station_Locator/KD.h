#include<stdio.h>

#define DIMENSION 2
typedef struct Node {
	int point[DIMENSION];
	struct Node *left, *right; 
}Node;
typedef Node* KDTree;

void initKDTree(KDTree* tree);
void insert(KDTree* tree, int point[]);
unsigned search(KDTree tree, int point[]);
void deleteNode(KDTree* tree, int point[]);
Node* nearestNeighbor(KDTree tree, int target[]);
void nearestNeighborInRadius(KDTree tree, int target[], int radius);
void traverse(KDTree tree);

