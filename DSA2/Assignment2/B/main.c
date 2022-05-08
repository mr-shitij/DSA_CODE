#include<stdio.h>
#include"BST.h"

int main() {
	int size;
	printf("\n Enter the Size Of Data : ");
	scanf("%d", &size);

	int data[size];
	int i = 0;
	while(i < size) {
		printf("\n Enter the Data : ");
		scanf("%d", &data[i]);
		i++;
	}
	
	BST tree = generateFromTree(data, 0, size - 1);
	inorder(tree);
	return 0;
}
