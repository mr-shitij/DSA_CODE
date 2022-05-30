#include<stdio.h>
#include<stdlib.h>
#include"KD.h"

void init_KDTree(KDTree* tree) {
	*tree = NULL;
}

KDTree newNode(int point[]) {
	KDTree node = malloc(sizeof(Node));
	
	for(int i = 0; i < DIMENSION; i++) {
		node->point[i] = point[i];
	}
	node->left = node->right = NULL;
	return node;
}

KDTree insertRecursively(KDTree tree, int point[], unsigned depth) {
	if(tree == NULL)
		return newNode(point);

	unsigned currentDepth = depth % DIMENSION;
	if(point[currentDepth] < tree->point[currentDepth])
		tree->left  = insertRecursively(tree->left, point, depth + 1);
	else
		tree->right = insertRecursively(tree->right, point, depth + 1);
	return tree;
}

void insert(KDTree* tree, int point[]) {
	KDTree kdt = *tree;
	kdt = insertRecursively(kdt, point, 0);
	*tree = kdt;
}

unsigned arePointsSame(int point1[], int point2[]) {
	for (int i = 0; i < DIMENSION; ++i)
		if (point1[i] != point2[i])
			return 0;
	return 1;
}

unsigned searchRecurrsively(KDTree tree, int point[], unsigned depth) {
	if (tree == NULL)
		return 0;
	if (arePointsSame(tree->point, point))
		return 1;

	unsigned currentDepth = depth % DIMENSION;
	if (point[currentDepth] < tree->point[currentDepth])
		return searchRecurrsively(tree->left, point, depth + 1);
	return searchRecurrsively(tree->right, point, depth + 1);
}

unsigned search(KDTree tree, int point[]) {
	return searchRecurrsively(tree, point, 0);
}

void traverse(KDTree tree) {
	if(tree != NULL) {
		traverse(tree->left);
		printf("\n %d : %d", tree->point[0], tree->point[1]);
		traverse(tree->right);
	} 
}


///*
KDTree minNode(KDTree x, KDTree y, KDTree z, int d) {
    KDTree res = x;
    if (y != NULL && y->point[d] < res->point[d])
       res = y;
    if (z != NULL && z->point[d] < res->point[d])
       res = z;
    return res;
}

void copyPoint(int p1[], int p2[]) {
	for (int i=0; i<DIMENSION; i++)
		p1[i] = p2[i];
}

KDTree findMinRec(KDTree tree, int d, unsigned depth) {
	if (tree == NULL)
		return NULL;

	unsigned currentDepth = depth % DIMENSION;
	if (currentDepth == d) {
		if (tree->left == NULL)
			return tree;
		return findMinRec(tree->left, d, depth + 1);
	}
	return minNode(tree, findMinRec(tree->left, d, depth + 1), findMinRec(tree->right, d, depth + 1), d);
}

KDTree findMin(KDTree tree, int d) {
    return findMinRec(tree, d, 0);
}

KDTree deleteNodeRec(KDTree tree, int point[], int depth) {
	if (tree == NULL)
		return NULL;

	int currentDepth = depth % DIMENSION;
	if (arePointsSame(tree->point, point)) {
		if (tree->right != NULL) {
			KDTree min = findMin(tree->right, currentDepth);
			copyPoint(tree->point, min->point);
			tree->right = deleteNodeRec(tree->right, min->point, depth + 1);
			
		}
		else if (tree->left != NULL) {
			Node *min = findMin(tree->left, currentDepth);
			copyPoint(tree->point, min->point);
			tree->right = deleteNodeRec(tree->left, min->point, depth + 1);
			
		}
		else {
			free(tree);
			return NULL;
			
		}
		return tree;
		
	}

	if (point[currentDepth] < tree->point[currentDepth])
		tree->left = deleteNodeRec(tree->left, point, depth + 1);
	else
		tree->right = deleteNodeRec(tree->right, point, depth + 1);
	return tree;
}

void deleteNode(KDTree* tree, int point[]) {
	*tree = deleteNodeRec(*tree, point, 0);
}
//*/
