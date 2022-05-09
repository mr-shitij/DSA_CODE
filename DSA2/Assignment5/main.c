#include<stdio.h>
#include"BHE.h"

int main(int args, char* arg[]) {
	BHE tree = NULL;
	initBHE(&tree);
	
	if(args != 2) {
		printf("Specify The File Name To Continue ..!!");
		return 1;
	}
	
	FILE* fp = fopen(arg[1], "r");
	
	int data;
	while(fscanf(fp, "%d\n", &data) == 1) {
		printf("%d\n", data);
	}
	
	fclose(fp);
		
	return 0;
}

