#include<stdio.h>
#include"BST.h"

int main() {
	int data[] = {5, 3, 7, 9, 13, 11, 19, 17, 21};
	BST tree = generateFromTree(data, 0, (sizeof(data) / sizeof(int)) - 1);
	inorder(tree);
	return 0;
}
