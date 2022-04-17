#include<stdio.h>
#include"BST.h"

/*
			10
		5		15

*/


int main() {
	int data[] = {5, 15, 10};
	BST tree = generateFromTree(data, 0, 2);
	inorder(tree);
	return 0;
}
