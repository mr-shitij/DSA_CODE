#include<stdio.h>

typedef struct DataNode {
	int mis;
	char* name;
	char* stream;
	double cgpa;
} DataNode;

void InsertRecord(char* fileName, DataNode data);
void Search(char* fileName, int mis);
void Delete(char* fileName, int mis);
void Display(char* fileName);


