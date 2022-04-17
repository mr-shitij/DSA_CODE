#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"BST.h"
#include"LinkList.h"


void initBST(BST *tree) {
	*tree = NULL;
}

Node* generateFromTree(int data[], int start, int end) {
	if(start > end) {
		return NULL;
	}
	
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->MIS = data[end];

	int i;
	for(i = end; i >= start; i--) {
		if(data[i] < newNode->MIS) {
			break;
		}
	}

	newNode->left = generateFromTree(data, start, i);
	newNode->right = generateFromTree(data, i + 1, end - 1);
	return newNode;
}

void insertNode(BST *tree, int data) {
	Node *newNode = (Node*) malloc(sizeof(Node));

	if(newNode == NULL) return;

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->MIS = data;

	Node *parentNode = NULL;
	Node *temp = *tree;

	while(temp != NULL) {
		parentNode = temp;
		if(temp->MIS == data) {
			free(newNode);
			return;
		}
		else if(temp->MIS > data) {
			temp = temp->left;
		}
		else {
			temp = temp->right;		
		}
	}

	if(parentNode == NULL) {
		*tree = newNode;
	}
	else if(parentNode->MIS > data) {
		parentNode->left = newNode;
	}
	else{
		parentNode->right = newNode;
	}
}

int search(BST tree, int MIS) { // to recursively search for a node with the given key.
	if(tree != NULL) {
		if(tree->MIS == MIS) {
			printf("\n DATA FOUND : %d", MIS);
			return 1;
		}
		else if(tree->MIS < MIS) {
			search(tree->right, MIS);
		}
		else {
			search(tree->left, MIS);
		}
		
	}
	return 0;
}

void inorder(BST tree) {
        if(tree != NULL) {
 		inorder(tree->left);
 		printf("\n MIS : %d", tree->MIS);
 		inorder(tree->right);
        }
}

void preorder(BST tree) {
        if(tree != NULL) {
 		printf("\n MIS : %d", tree->MIS);
		preorder(tree->left);
		preorder(tree->right);
        }
}

void postorder(BST tree) {
	if(tree != NULL) {
		postorder(tree->left);
		postorder(tree->right);
 		printf("\n MIS : %d", tree->MIS);
	}
}

void Display_Level(BST tree, int level) { // Level Wise traversal
	if(tree != NULL) {
		if(level == 0)
			printf("\n %d", tree->MIS);
		else {
			Display_Level(tree->left, level - 1);
			Display_Level(tree->right, level - 1);
		}
	}
}

void removeNode(BST *tree, int MIS) {
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
			BST parentOfMinNode = crrentNode;
			BST minNode = crrentNode->right;

			while(minNode->left != NULL) {
				parentOfMinNode = minNode;
				minNode = minNode->left;
			}
			if(parentOfMinNode == crrentNode)
				parentOfMinNode->right = minNode->right;
			else if(parentOfMinNode != NULL)
				parentOfMinNode->left = minNode->right;
	
			crrentNode->MIS = minNode->MIS;
			free(minNode);
		}
	}
}

void destoryTree(BST tree) {
	if(tree != NULL) {
		destoryTree(tree->left);
		destoryTree(tree->right);
		free(tree);
	}
}

