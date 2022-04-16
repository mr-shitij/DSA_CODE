#include<stdio.h>
#include"BST.h"

int main() {
	BST tree;
	init_bst(&tree);
	int i = 0, data, j;
	do {
		printf("\n 1.Insert");
		printf("\n 2.Recursive Traverse");
		printf("\n 3.IsComplete");
		printf("\n 4.Exit");
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
			case 3:
				j = isComplete(tree);
				if(j == 0)
					printf("Not Complete\n");
				else
					printf("Complete\n");				
				break;
		}
		
	} while (i != 4);
	return 0;
}
