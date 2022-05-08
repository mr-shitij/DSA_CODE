#include<stdio.h>
#include"AVL.h"

int main() {
	AVL tree = NULL, tempTree = NULL, tempParentTree = NULL;
	initAVL(&tree);
	int i = 0, data;
	char name[NAME_SIZE];
	do {
		printf("\n 1.Insert");
		printf("\n 2.Traverse");
		printf("\n 3.Remove");
		printf("\n 4.Exit");
		printf("\n Select Choice : ");
		scanf("%d", &i);

		switch(i) {
			case 1:
				printf("\n Enter the data : ");
				scanf("%d", &data);

				printf("\n Enter the name : ");
				scanf("%s", name);

				insertNode(&tree, data, name);
				break;
			case 2:
				traverse(tree);
				break;
			case 3:
				printf("\n Enter the MIS : ");
				scanf("%d", &data);                        
				removeNode(&tree, data);
				break;
			case 4:
				break;
		}
		
	} while (i != 4);
	return 0;
}
