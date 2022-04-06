#include<stdio.h>
#include"BST.h"

int main() {
	BST tree;
	initBST(&tree);
	int i = 0, data;
	do {
		printf("\n 1.Insert");
		printf("\n 2.PreOrder");
	        printf("\n 3.InOrder");
                printf("\n 4.PostOrder");
		printf("\n 5.Exit");
		printf("\n Select Choice : ");
		scanf("%d", &i);
		
		switch(i) {
			case 1:
				printf("\n Enter the data : ");
				scanf("%d", &data);
				insertNode(&tree, data);
				break;
			case 2:
				preorder(tree);
				break;
		
	                case 3:
                                inorder(tree);
                                break;
                        case 4:
                                postorder(tree);
                                break;

		}


	} while (i != 5);
	return 0;
}
