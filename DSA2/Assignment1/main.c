#include<stdio.h>
#include"BST.h"

int main() {
	BST tree, tempTree;
	initBST(&tree);
	int i = 0, data;
	do {
		printf("\n 1.Insert");
		printf("\n 2.PreOrder");
		printf("\n 3.InOrder");
		printf("\n 4.PostOrder");
		printf("\n 5.Search");
		printf("\n 6.Display Level");
		printf("\n 7.Exit");
		printf("\n Select Choice : ");
		scanf("%d", &i);

		switch(i) {
			case 1:
				printf("\n Enter the data : ");
				scanf("%d", &data);
				// we are checking this condition because if root is null then we can directly assign newNode to it but if it is not
				// then we have to create tempNode and then use it in recurrsion to insert new node so that reference to root not going to lost.
				tempTree = tree;
				if(tree == NULL)
					insertNode(&tree, data);
				else
					insertNode(&tempTree, data);
				break;
			case 2:
				preorder(tree);
				break;
		
	                case 3:
				inorder(tree);
				break;
                        case 4:
				postorderNonRecursive(tree);
				break;
                        case 5:
                        	printf("\n Enter the MIS : ");
                        	scanf("%d", &data);
				search(tree, data);
				break;
                        case 6:
                        	printf("\n Enter the Level : ");
                        	scanf("%d", &data);                        
				Display_Level(tree, data);
				break;

		}

	} while (i != 7);
	return 0;
}
