#include<stdio.h>
#include"BST.h"

int main() {
	BST tree = NULL, tempTree = NULL, tempParentTree = NULL;
	initBST(&tree);
	int i = 0, data;
	char name[NAME_SIZE];
	do {
		printf("\n 1.Insert");
		printf("\n 2.PreOrder");
		printf("\n 3.InOrder");
		printf("\n 4.PostOrder");
		printf("\n 5.Search");
		printf("\n 6.Remove");
		printf("\n 7.Display Level");
		printf("\n 8.Exit");
		printf("\n Select Choice : ");
		scanf("%d", &i);

		switch(i) {
			case 1:
				printf("\n Enter the data : ");
				scanf("%d", &data);

				printf("\n Enter the name : ");
				scanf("%s", name);

				// we are checking this condition because if root is null then we can directly assign newNode to it but if it is not
				// then we have to create tempNode and then use it in recurrsion to insert new node so that reference to root not going to lost.
				tempTree = tree;
				if(tree == NULL)
					insertNode(&tree, &tempParentTree, data, name);
				else
					insertNode(&tempTree, &tempParentTree, data, name);
				//insertNodeWithoutRecurrsion(&tree, data, name);
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
				printf("\n Enter the MIS : ");
				scanf("%d", &data);                        
				removeNode(&tree, data);
				break;
			case 7:
				printf("\n Enter the Level : ");
				scanf("%d", &data);                        
				Display_Level(tree, data);
				break;
		}
		
	} while (i != 8);
	return 0;
}
