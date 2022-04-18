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
		while(index < (*tree)->size && (*tree)->array[index] != INT_MIN) {
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

void _inorder(BST tree, int index) {
	if(tree != NULL && tree->array[index] != INT_MIN) {
		_inorder(tree, index * 2 + 1);
		printf("%d\n", tree->array[index]);
		_inorder(tree, index * 2 + 2);
	}
}

void _preorder(BST tree, int index) {
	if(tree != NULL && tree->array[index] != INT_MIN) {
		printf("%d\n", tree->array[index]);
		_inorder(tree, index * 2 + 1);
		_inorder(tree, index * 2 + 2);
	}
}

void _postorder(BST tree, int index) {
	if(tree != NULL && tree->array[index] != INT_MIN) {
		_inorder(tree, index * 2 + 1);
		_inorder(tree, index * 2 + 2);
		printf("%d\n", tree->array[index]);
	}
}

void recursive_traverse_inorder(BST tree) {
	_inorder(tree, 0);
}

void recursive_traverse_postorder(BST tree) {
	_postorder(tree, 0);
}

void recursive_traverse_preorder(BST tree) {
	_preorder(tree, 0);
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


