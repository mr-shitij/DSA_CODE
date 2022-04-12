#include<stdio.h>
#include"BST.h"

int main() {
	BST tree = NULL;
	init_bst(&tree);
	int i = 0, data;
	do {
		printf("\n 1.Insert");
		printf("\n 2.PreOrder");
		printf("\n 3.Exit");
		printf("\n Select Choice : ");
		scanf("%d", &i);

		switch(i) {
			case 1:
				printf("\n Enter the data : ");
				scanf("%d", &data);
				insert_bst(&tree, data);
				break;
			case 2:
				recursive_traverse(tree, 0);
				break;
		}
		
	} while (i != 3);
	return 0;
}
