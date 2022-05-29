#include<stdio.h>
#include"KD.h"

int main() {
	int choice = 0;
	KDTree tree;
	init_KDTree(&tree);
	int point[DIMENSION] = {10, 20};

	while(choice != 4) {
		printf("\n 1. Insert");
		printf("\n 2. Search");
		printf("\n 3. Delete");
		printf("\n 4. Exit");
		printf("\n Select Your Choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("\n Enter The Element To Insert : ");
				for(int i=0; i<DIMENSION; i++) {
					scanf("%d", &point[i]);
				}
				insert(&tree, point);
				break;
			case 2:
				printf("\n Enter The Element To Search : ");
				for(int i=0; i<DIMENSION; i++) {
					scanf("%d", &point[i]);
				}
				printf("\n Search Result : %d", search(tree, point));
				break;
			case 3:
				printf("\n Enter The Element To Search : ");
				for(int i=0; i<DIMENSION; i++) {
					scanf("%d", &point[i]);
				}
				deleteNode(&tree, point);
				break;
			case 4:
				break;
			default:
				printf("\n Invalid Choice ..!!");
				break;				
		}
	}
	return 0;
}

