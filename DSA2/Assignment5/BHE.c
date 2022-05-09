#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"BHE.h"


void initBHE(BHE *tree) {
	*tree = NULL;
}

BHE insert(BHE *tree, BHE *parentTree, int data) {
	if(*tree == NULL) {
		*tree = malloc(sizeof(Node));
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		(*tree)->parent = (*parentTree);
		(*tree)->data = data;
		return *tree;
		
	}
	else if((*tree)->data == data) {
		return NULL;
	}
	else if((*tree)->data > data) {
		(*parentTree) = *tree;
		insert(&((*tree)->left), &(*parentTree), data);
	}
	else if((*tree)->data < data) {
		(*parentTree) = *tree;
		insert(&((*tree)->right), &(*parentTree), data);
	}
}

void insertNode(BHE *tree, int data) {
	BHE tempTree = NULL, tempParentTree = NULL;
	BHE insertedNode = NULL;
	tempTree = *tree;
	if(*tree == NULL)
		insertedNode = insert(&(*tree), &tempParentTree, data);
	else
		insertedNode = insert(&tempTree, &tempParentTree, data);

}

void traverse(BHE tree) {
        if(tree != NULL) {
		printf("%d \n", tree->data);
 		traverse(tree->left);
 		traverse(tree->right);
        }
}

void removeNode(BHE* tree, int data) {
	if(tree != NULL) {
		Node *parentNode = NULL;
		Node *crrentNode = *tree;
		// Search for the existance of the element
		while(crrentNode != NULL) {
			if(crrentNode->data == data) {
				break;
			}
			parentNode = crrentNode;
			if(crrentNode->data < data) {
				crrentNode = crrentNode->right;
			}
			else {
				crrentNode = crrentNode->left;
			}
		}
		// if current is null means not found
		if(crrentNode == NULL) {
			return;
		}


		/* Node with 0 child */
		if(crrentNode->left == NULL && crrentNode->right == NULL) {
			// if parentNode is not null means the node is not of root
			if(parentNode != NULL) {
				if(parentNode->left == crrentNode) {
					parentNode->left = NULL;
				}
				else {
					parentNode->right = NULL;				
				}
			}
			else{
				*tree = NULL;
			}
			free(crrentNode);
			crrentNode = NULL;
			return;
		}

		/* Node with 1 child */
		if(crrentNode->left != NULL && crrentNode->right == NULL) {
			// if parentNode is not null means the node is not of root
			if(parentNode != NULL) {
				if(parentNode->left == crrentNode) {
					parentNode->left = crrentNode->left;
				}
				else {
					parentNode->right = crrentNode->left;
				}
			}
			else{
				*tree = crrentNode->left;
			}
			free(crrentNode);
			crrentNode = NULL;
			return;
		}
		else if(crrentNode->left == NULL && crrentNode->right != NULL) {
			// if parentNode is not null means the node is not of root
			if(parentNode != NULL) {
				if(parentNode->right == crrentNode) {
					parentNode->right = crrentNode->right;
				}
				else {
					parentNode->left = crrentNode->right;
				}
			}
			else{
				*tree = crrentNode->right;
			}
			free(crrentNode);
			crrentNode = NULL;
			return;
		}

		/* Node with 2 child */
		if(crrentNode->left != NULL && crrentNode->right != NULL) {
			// Find the minimum node from the right subtree (inorder successor)
			BHE parentOfMinNode = crrentNode;
			BHE minNode = crrentNode->right;

			while(minNode->left != NULL) {
				parentOfMinNode = minNode;
				minNode = minNode->left;
			}
			if(parentOfMinNode == crrentNode)
				parentOfMinNode->right = minNode->right;
			else if(parentOfMinNode != NULL)
				parentOfMinNode->left = minNode->right;


			crrentNode->data = minNode->data;

			free(minNode);

		}
	}
}

void destoryTree(BHE *tree) {
	if(*tree != NULL) {
		destoryTree(&(*tree)->left);
		destoryTree(&(*tree)->right);
		free((*tree));
	}
}

