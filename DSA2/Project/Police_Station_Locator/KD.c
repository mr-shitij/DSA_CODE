#include<stdio.h>
#include<stdlib.h>
#include"KD.h"

Node* nearestNeighborRecur(Node* root, int target[], int depth);
long distSquared(int p0[], int p1[]);

int Pow(int X, int Y) {

	int power = 1, i;

	for (i = 1; i <= Y; ++i) {
		power = power * X;
	}
	return power;
}

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

Node* nearestNeighbor(KDTree tree, int target[]) {
	return nearestNeighborRecur(tree, target, 0);
}

long distSquared(int p0[], int p1[]) {
	long total = 0;
	int numDims = DIMENSION;

	for(int i = 0; i < numDims; i++) {
		int diff = abs(p0[i % DIMENSION] - p1[i % DIMENSION]);
		total += Pow(diff, 2);
	}
	return total;
}

Node* closest(Node* n0, Node* n1, int target[]) {
	if (n0 == NULL) return n1;

	if (n1 == NULL) return n0;

	long d1 = distSquared(n0->point, target);
	long d2 = distSquared(n1->point, target);

	if (d1 < d2)
		return n0;
	else
		return n1;
}

Node* nearestNeighborRecur(Node* root, int target[], int depth) {
	if (root == NULL) return NULL;

	Node* nextBranch = NULL;
	Node* otherBranch = NULL;

	// compare the property appropriate for the current depth
	if (target[depth % DIMENSION] < root->point[depth % DIMENSION]) {
		nextBranch = root->left;
		otherBranch = root->right;
	} else {	    
		nextBranch = root->right;
		otherBranch = root->left;
	}

	// recurse down the branch that's best according to the current depth
	Node* temp = nearestNeighborRecur(nextBranch, target, depth + 1);
	Node* best = closest(temp, root, target);

	long radiusSquared = distSquared(target, best->point);

	/*
	* We may need to check the other side of the tree. If the other side is closer than the radius,
	* then we must recurse to the other side as well. 'dist' is either a horizontal or a vertical line
	* that goes to an imaginary line that is splitting the plane by the root point.
	*/
	long dist = target[depth % DIMENSION] - root->point[depth % DIMENSION];

	if (radiusSquared >= dist * dist) {
		temp = nearestNeighborRecur(otherBranch, target, depth + 1);
		best = closest(temp, best, target);
	}

	return best;
}

Node* nearestNeighborInRadiusRecur(Node* root, int target[], int radius, int depth) {
	if (root == NULL) return NULL;

	Node* nextBranch = NULL;
	Node* otherBranch = NULL;

	// compare the property appropriate for the current depth
	if (target[depth % DIMENSION] < root->point[depth % DIMENSION]) {
		nextBranch = root->left;
		otherBranch = root->right;
	} else {	    
		nextBranch = root->right;
		otherBranch = root->left;
	}

	// recurse down the branch that's best according to the current depth
	Node* temp = nearestNeighborInRadiusRecur(nextBranch, target, radius, depth + 1);
	Node* best = closest(temp, root, target);
	printf("Nearest : { %d : %d } \n", best->point[0], best->point[1]);

	long radiusSquared = distSquared(target, best->point);
	printf("radiusSquared : { %d } \n", radiusSquared);

	/*
	* We may need to check the other side of the tree. If the other side is closer than the radius,
	* then we must recurse to the other side as well. 'dist' is either a horizontal or a vertical line
	* that goes to an imaginary line that is splitting the plane by the root point.
	*/
	long dist = target[depth % DIMENSION] - root->point[depth % DIMENSION];

	if (radiusSquared >= dist * dist && radius * radius < radiusSquared) {
		temp = nearestNeighborInRadiusRecur(otherBranch, target, radius, depth + 1);
		best = closest(temp, best, target);
		
		printf("Nearest : { %d : %d } \n", best->point[0], best->point[1]);
		
	}

	return best;	
}

void nearestNeighborInRadius(KDTree tree, int target[], int radius) {
	nearestNeighborInRadiusRecur(tree, target, radius, 0);
}



 
