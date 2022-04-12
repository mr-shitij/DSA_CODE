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
		int index = 0;
		while(index < (*tree)->size && (*tree)->array[index] == INT_MIN) {
			if((*tree)->array[index] == data) {
				return;
			}
			else if((*tree)->array[index] < data) {
                		index = index*2 + 2;
			}
			else {
                        	index = index*2 + 1;
                	}
		}
		if(!(index < (*tree)->size)) return;
		(*tree)->array[index] = data;
	}
}

void recursive_traverse(BST tree, int index) {
	if(tree != NULL) {
		recursive_traverse(tree, index * 2 + 1);
		printf("%d\n", tree->array[index]);
		recursive_traverse(tree, index * 2 + 2);
	}
}

int isComplete(BST tree) {

}

