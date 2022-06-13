#include<stdlib.h>
#include"randomGenrator.h"
#ifndef _KD
	#include"KD.h"
#endif

void generateRandomPoints(char* fileName, int n, int maxx, int maxy) {
	FILE* fp = fopen(fileName, "w+");
	fprintf(fp, "%d\n", n);
	while(n != 0) {
		int numx = rand() % maxx + 1;
		int numy = rand() % maxy + 1;
		fprintf(fp, "%d,%d\n", numx, numy);
		n--;
	}
	fclose(fp);
}

KDTree getRandomPoints(char* fileName) {
	KDTree tree;
	initKDTree(&tree);
	int point[DIMENSION];

	int n;
	FILE* fp = fopen(fileName, "r");
	fscanf(fp, "%d\n", &n);

	while(n != 0) {
		int numx, numy;
		fscanf(fp, "%d , %d\n", &numx, &numy);
	
		point[0] = numx;
		point[1] = numy;
		insert(&tree, point);	

		n--;
	}
	fclose(fp);
	return tree;
}


