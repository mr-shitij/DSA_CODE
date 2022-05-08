#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"AVL.h"


void initAVL(AVL *tree) {
	*tree = NULL;
}

AVL insert(AVL *tree, AVL *parentTree, int data, char name[]) {
	if(*tree == NULL) {
		*tree = malloc(sizeof(Node));
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		strcpy((*tree)->name, name);
		(*tree)->parent = (*parentTree);
		(*tree)->MIS = data;
		return *tree;
		
	}
	else if((*tree)->MIS == data) {
		return NULL;
	}
	else if((*tree)->MIS > data) {
		(*parentTree) = *tree;
		insert(&((*tree)->left), &(*parentTree), data, name);
	}
	else if((*tree)->MIS < data) {
		(*parentTree) = *tree;
		insert(&((*tree)->right), &(*parentTree), data, name);
	}
}

int getHeight(AVL tree) {
	if(tree == NULL) {
		return -1;
	}

	int hl = getHeight(tree->left);
	int hr = getHeight(tree->right);
	
	if(hl > hr)
		return hl + 1;
	else
		return hr + 1;

}

void adjustBalanceFactor(AVL* tree) {
	if((*tree)->parent != NULL) {
		int balanceFactor = getHeight((*tree)->left) - getHeight((*tree)->right);
		(*tree)->balanceFactor = balanceFactor;
		adjustBalanceFactor(&((*tree)->parent));
	}
}

void rotateLeft(AVL* nodeA) {
	AVL nodeB = (*nodeA)->right;
	(nodeB)->parent = (*nodeA)->parent;
	(*nodeA)->parent = nodeB;
	
	(*nodeA)->right = nodeB->left;
	nodeB->left = *nodeA;	
}

void rotateRight(AVL* nodeA) {
	AVL nodeB = (*nodeA)->left;
	(nodeB)->parent = (*nodeA)->parent;
	(*nodeA)->parent = nodeB;
	
	(*nodeA)->left = nodeB->right;
	nodeB->right = *nodeA;
}

void insertNode(AVL *tree, int data, char name[]) {
	AVL tempTree = NULL, tempParentTree = NULL;
	AVL insertedNode = NULL;
	tempTree = *tree;
	if(*tree == NULL)
		insertedNode = insert(&(*tree), &tempParentTree, data, name);
	else
		insertedNode = insert(&tempTree, &tempParentTree, data, name);

	adjustBalanceFactor(&insertedNode);
	if(insertedNode->balanceFactor > 1 && insertedNode->left->balanceFactor == 1) {
		rotateLeft(&insertedNode);
	}
	else if(insertedNode->balanceFactor > 1 && insertedNode->left->balanceFactor == -1) {
		rotateLeft(&insertedNode);
		rotateRight(&insertedNode);		
	}
	else if(insertedNode->balanceFactor < -1 && insertedNode->right->balanceFactor == -1) {
		rotateRight(&insertedNode);		
	}
	else if(insertedNode->balanceFactor < -1 && insertedNode->right->balanceFactor == 1) {
		rotateRight(&insertedNode);		
		rotateLeft(&insertedNode);
	}
	adjustBalanceFactor(&insertedNode);
}

void traverse(AVL tree) {
        if(tree != NULL) {
 		traverse(tree->left);
		printf("%d  :  %d \n", tree->MIS, tree->balanceFactor);
 		traverse(tree->right);
        }
}

void removeNode(AVL* tree, int MIS) {
	if(tree != NULL) {
		Node *parentNode = NULL;
		Node *crrentNode = *tree;
		// Search for the existance of the element
		while(crrentNode != NULL) {
			if(crrentNode->MIS == MIS) {
				break;
			}
			parentNode = crrentNode;
			if(crrentNode->MIS < MIS) {
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
			AVL parentOfMinNode = crrentNode;
			AVL minNode = crrentNode->right;

			while(minNode->left != NULL) {
				parentOfMinNode = minNode;
				minNode = minNode->left;
			}
			if(parentOfMinNode == crrentNode)
				parentOfMinNode->right = minNode->right;
			else if(parentOfMinNode != NULL)
				parentOfMinNode->left = minNode->right;


			crrentNode->MIS = minNode->MIS;
			strcpy(minNode->name, crrentNode->name);

			free(minNode);	

		}
	}
}

void destoryTree(AVL *tree) {
	if(*tree != NULL) {
		destoryTree(&(*tree)->left);
		destoryTree(&(*tree)->right);
		free((*tree));
	}
}

