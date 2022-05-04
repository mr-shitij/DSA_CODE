#include<stdio.h>
#include"BST.h"

int main() {
	EXT tree;
	initTree(&tree, "1+2-3*6", 17);
	traverse(tree);
	
	printf("COMPUTE : %d", compute(tree));
		
	return 0;
}
