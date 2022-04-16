#include<stdio.h>
#include <limits.h>
#include"BST.h"

void init_bst(BST *tree) {
	(*tree)->size = SIZE_TREE;
	(*tree)->array = malloc(sizeof(int) * (*tree)->size);
	
	for(int i=0; i < SIZE_TREE; i++) {
		(*tree)->array[i] = INT_MIN;
	}
}

void insert_bst(BST *tree, int data) {
	if((*tree) != NULL) {
		printf("\n H0");
		int index = 0;
		while(index < (*tree)->size && (*tree)->array[index] != INT_MIN) {
			printf("\n H1");
			if((*tree)->array[index] == data) {
				return;
			}
			else if((*tree)->array[index] < data) {
                		index = index*2 + 2;
			}
			else {
                        	index = index*2 + 1;
                	}
			printf("\n Index : %d", index);
		}
		printf("\n HELLO");
		if(!(index < (*tree)->size)) return;
		(*tree)->array[index] = data;
		printf("\n Data : %d", (*tree)->array[index]);
	}
}

void recursive_traverse(BST tree, int index) {
	if(tree != NULL && tree->array[index] != INT_MIN) {
		recursive_traverse(tree, index * 2 + 1);
		printf("%d\n", tree->array[index]);
		recursive_traverse(tree, index * 2 + 2);
	}
}

int isComplete(BST tree) {
	if(tree == NULL)
		return 0;

	int index = 0;
	while(index < tree->size && tree->array[index] != INT_MIN) {
		index++;
	}

	while(index < tree->size && tree->array[index] == INT_MIN) {
		index++;
	}

	if(index < tree->size) {
		return 0;
	}
	return 1;	
}


