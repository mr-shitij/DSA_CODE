#include<stdio.h>
#include"KD.h"
#include"randomGenrator.h"

int main(int argc, char* argv[]) {

/*
	switch(argc) {
		case 0:
		case 1:
			printf("\n Please Pass The requried arguments ..!!");
			break;
		case 2:
			printf("\n Findig The ");
			break;
			
	}

*/

	char fileName[] = "data.txt";
	generateRandomPoints(fileName, 100, 500, 500);
	int point[] = {200, 200};
	KDTree tree = getRandomPoints(fileName);

//	Node* node = nearestNeighbor(tree, point);
//	printf("Nearest Node is : { %d : %d } \n", node->point[0], node->point[1]);

	nearestNeighborInRadius(tree, point, 30);

//	traverse(tree);
	
	return 0;
}


/*
	while(choice != 6) {
		printf("\n 1. Insert");
		printf("\n 2. Search");
		printf("\n 3. Delete");
		printf("\n 4. Nearest Search");
		printf("\n 5. Traverse");
		printf("\n 6. Exit");
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
				printf("\n Enter The Element : ");
				for(int i=0; i<DIMENSION; i++) {
					scanf("%d", &point[i]);
				}
				Node* node = nearestNeighbor(tree, point);
				printf("\n Nearest Node is : { %d : %d }", node->point[0], node->point[1]);
				break;
			case 5:
				traverse(tree);
				break;
			case 6:
				break;
			default:
				printf("\n Invalid Choice ..!!");
				break;				
		}
	}
*/

