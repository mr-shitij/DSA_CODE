#include<stdio.h>
#include"BST.h"

/*
			10
		5		15

*/


int main() {
	BST tree = NULL, tempTree = NULL, tempParentTree = NULL;
	initBST(&tree);
	int data[] = {5, 15, 10}
	Node *tree = generateFromTree(data, start, 3);
	
	inorder(tree);
	return 0;
}
