#include<stdio.h>
#include<stdlib.h>
#include"FO.h"

void InsertRecord(char* fileName, DataNode data) {
	FILE *file = fopen(fileName, "ab+");
	if(file == NULL) {
		return;
	}
	
	printf("HELLO\n\n\n");
	fwrite(&data, sizeof(DataNode), 1, file);
	printf("HELLOIIII\n\n\n");
	fclose(file);
}

void print(DataNode data) {
	printf("\n MIS : %d, Name : %s, Stream : %s, CGPA : %lf", data.mis, data.name, data.stream, data.cgpa);
}

void Search(char* fileName, int mis) {
	FILE *file = fopen(fileName, "rb");
	if(file == NULL) {
		return;
	}
	
	DataNode data;
	while(fread(&data, sizeof(DataNode), 1, file)) {
		if(data.mis == mis) {
			printf("\n Found ..!!");
			print(data);
		}
	}
	fclose(file);
}

void Delete(char* fileName, int mis) {
	FILE *fileToRead = fopen(fileName, "rb");
	FILE *fileToWrite = fopen("_temp", "wb+");
	
	if(fileToRead == NULL || fileToWrite == NULL) {
		return;
	}
	
	DataNode data;
	while(fread(&data, sizeof(DataNode), 1, fileToRead)) {
		if(data.mis == mis) {
			continue;
		}
		fwrite(&data, sizeof(DataNode), 1, fileToWrite);
	}
	fclose(fileToRead);
	fclose(fileToWrite);

	remove(fileName);
	int value = rename("_temp", fileName);
	if(!value) {
		printf("%s", "File name changed successfully");
	}
	else {
		perror("Error");
	}
}

void Display(char* fileName) {
	FILE *file = fopen(fileName, "rb");
	printf("HELLO\n\n");
	if(file == NULL) {
		printf("HELLO RET\n\n");
		return;
	}
	
	printf("HELLO DATA\n\n");
	DataNode data;
	while(fread(&data, sizeof(DataNode), 1, file)) {
		printf("HELLO DAAAAA\n\n");
		print(data);
	}
	fclose(file);
}


