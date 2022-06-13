#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"KD.h"
#include"randomGenrator.h"

/*

Command To Try ..!!

fileName n px py 	-> generate KD-Tree from given file and perform nearest neighbor search.
fileName r px py r	-> generate KD-Tree from given file and search in a radius 'r'.
fileName t 		-> generate KD-Tree and give the traversal.
fileName g n mx my 	-> generate 'n' numeber of random points having maximum 'x' of 'mx' and maximum 'y' of 'my'.

*/

int main(int argc, char* argv[]) {
	char fileName[100];
	char mode[5];
	switch(argc) {
		case 0:
		case 1:
		case 2:
			printf("\n Please Pass The requried arguments ..!!");
			break;
		case 3:
		case 4:
		case 5:
		case 6:
			strcpy(fileName, argv[1]);
			strcpy(mode, argv[2]);

			if(strcmp(mode, "n") == 0) {
				KDTree tree = getRandomPoints(fileName);			
				char point1Str[100], point2Str[100];
				int points[2];

				if(argc <= 4) {
					printf("\n Please Pass The requried arguments for function ..!!");
					return 1;
				}
				strcpy(point1Str, argv[3]);
				strcpy(point2Str, argv[4]);

				points[0] = atoi(point1Str);
				points[1] = atoi(point2Str);
				
				Node* node = nearestNeighbor(tree, points);
				printf("Nearest Node is : { %d : %d } \n", node->point[0], node->point[1]);
			} else if(strcmp(mode, "r") == 0) {
				KDTree tree = getRandomPoints(fileName);			
				char point1Str[100], point2Str[100], radiusStr[100];
				int points[2], radius;

				if(argc <= 5) {
					printf("\n Please Pass The requried arguments for function ..!!");
					return 1;
				}

				strcpy(point1Str, argv[3]);
				strcpy(point2Str, argv[4]);
				strcpy(radiusStr, argv[5]);

				points[0] = atoi(point1Str);
				points[1] = atoi(point2Str);
				radius = atoi(radiusStr);

				nearestNeighborInRadius(tree, points, radius);
			} else if(strcmp(mode, "t") == 0) {
				KDTree tree = getRandomPoints(fileName);
				traverse(tree);
			} else if(strcmp(mode, "g") == 0) {
				int n, mx, my;
				if(argc <= 5) {
					printf("\n Please Pass The requried arguments for function ..!!");
					return 1;
				}

				n = atoi(argv[3]);
				mx = atoi(argv[4]);
				my = atoi(argv[5]);

				generateRandomPoints(fileName, n, mx, my);
			} else {
				printf("\n Invalid ..!!");
			}
			break;
	}
	return 0;
}
