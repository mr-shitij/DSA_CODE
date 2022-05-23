#include<stdio.h>
#include<stdlib.h>  
#include"GEN.h"

void generate_random_data(char file_name[], int no) {
	int data;
	FILE* fp = fopen(file_name, "w");
	while (no != 0) {
		data = rand() % 100;
		fprintf(fp, "%d\n", data);
		no--;
	}

	fclose(fp);
}

void print_data(char file_name[]) {
	int data;
	FILE* fp = fopen(file_name, "r");
	while (fscanf(fp, "%d\n", &data) == 1) {
		printf("%d\n", data);
	}

	fclose(fp);
}

