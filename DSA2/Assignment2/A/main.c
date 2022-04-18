#include<stdio.h>
#include <limits.h>
#include"BST.h"

int main() {
	BST tree;
	init_bst(&tree);
	int i = 0, data, j;
	do {
		printf("\n 1.Insert");
		printf("\n 2.Inorder Recursive Traverse");
		printf("\n 3.Preorder Recursive Traverse");
		printf("\n 4.Postorder Recursive Traverse");
		printf("\n 5.IsComplete");
		printf("\n 6.Exit");
		printf("\n Select Choice : ");
		scanf("%d", &i);

		switch(i) {
			case 1:
				printf("\n Enter the data : ");
				scanf("%d", &data);
				insert_bst(&tree, data);
				break;
			case 2:
				recursive_traverse_inorder(tree);
				break;
			case 3:
				recursive_traverse_preorder(tree);
				break;
			case 4:
				recursive_traverse_postorder(tree);
				break;
			case 5:
				j = isComplete(tree);
				if(j == 0)
					printf("Not Complete\n");
				else
					printf("Complete\n");				
				break;
		}
		
	} while (i != 6);
	return 0;
}
