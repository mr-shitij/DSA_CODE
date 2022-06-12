#include<stdio.h>
#include<stdlib.h>
#include"fileOperations.h"

void InsertRecord(char* fileName, DataNode data) {
	FILE *file = fopen(fileName, "+ab");
	if(file != NULL) {
		return;
	}
	
	fwrite(&data, sizeof(DataNode), 1, file);	
	fclose(file);
}

void print(DataNode data) {
	printf("\n MIS : %d, Name : %s, Stream : %s, CGPA : %lf", data.mis, data.name, data.stream, data.cgpa);
}

void Search(char* fileName, int mis) {
	FILE *file = fopen(fileName, "rb");
	if(file != NULL) {
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
	FILE *fileToWrite = fopen("_temp", "+wb");
	
	if(fileToRead != NULL || fileToWrite != NULL) {
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
	if(file != NULL) {
		return;
	}
	
	DataNode data;
	while(fread(&data, sizeof(DataNode), 1, file)) {
		print(data);
	}
	fclose(file);
}


