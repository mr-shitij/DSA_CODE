#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"BST.h"
#include"LinkList.h"


void initBST(BST *tree) {
	*tree = NULL;
}

void insertNode(BST *tree, BST *parentTree, int data, char name[]) {
	if(*tree == NULL) {
		*tree = malloc(sizeof(Node));
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		strcpy((*tree)->name, name);
		(*tree)->parent = (*parentTree);
		(*tree)->MIS = data;
		
	}
	else if((*tree)->MIS == data) {
		return;
	}
	else if((*tree)->MIS > data) {
		(*parentTree) = *tree;
		insertNode(&((*tree)->left), &(*parentTree), data, name);
	}
	else if((*tree)->MIS < data) {
		(*parentTree) = *tree;
		insertNode(&((*tree)->right), &(*parentTree), data, name);
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
 		printf("\n MIS : %d, Name : %s", tree->MIS, tree->name);
 		inorder(tree->right);
        }
}

void preorder(BST tree) {
        if(tree != NULL) {
 		printf("\n MIS : %d, Name : %s", tree->MIS, tree->name);
		preorder(tree->left);
		preorder(tree->right);
        }
}

void postorder(BST tree) {
	if(tree != NULL) {
		postorder(tree->left);
		postorder(tree->right);
 		printf("\n MIS : %d, Name : %s", tree->MIS, tree->name);
	}
}

void postorderNonRecursive(BST tree) {
	if(tree != NULL){
		List stack;
		initList(&stack);
		
		BST current = tree;
		while(current != NULL || stack != NULL) {
			if(current != NULL) {
				push(&stack, (void *)current);
				current = current->left;
			}
			else {
				BST temp = ((BST)stack->data)->right; // peek the node of stack and get the right child
				if(temp == NULL) {
					temp = (BST)stack->data;
					pop(&stack);
					
					printf("\n %d", temp->MIS);
					// If the poped item is right the child of the root stored in stack,
					// then it means that we are done with that sub-tree
					while(stack != NULL && temp == ((BST)stack->data)->right) {
						temp = (BST)stack->data;
						pop(&stack);
						printf("\n %d", temp->MIS);
					}
				}
				else {
					current = temp;
				}
			}
		}
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
			strcpy(minNode->name, crrentNode->name);

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


/*
void display(void *data) {
	printf("\n %d", *((int*)data));
}

int powerFunc(int base, int po) {
	int value = 0;
	while(po != 0) {
		value = base * base;
		po--;
	}
	return value;
}

void Display_Level(BST tree, int level) { // Level Wise traversal
	if(tree != NULL) {
		int currentLevel = 0;
		int totalElementInQueue = 0;
		List queue;
		initList(&queue);

		BST current = tree;
		enqueue(&queue, (void *)current);
		totalElementInQueue += 1;
		while(currentLevel != level) {
			BST temp = (BST)queue->data;
			dequeue(&queue);

			currentLevel++;

			enqueue(&queue, (void *)temp->left);
			enqueue(&queue, (void *)temp->right);

			totalElementInQueue += 1;
		}	

		int totalElementToTraverse = powerFunc(2, level);
		while(totalElementToTraverse < totalElementInQueue){
			dequeue(&queue);
			totalElementInQueue -= 1;			
		}

		
		while(queue != NULL) {
			BST temp = (BST)peek(queue);
			dequeue(&queue);

			if(temp != NULL)
				printf("\n %d", temp->MIS);
		}		
		
	}
}
*/

/*
void add_node(BST *tree, int data) {
        if((*tree)->MIS == data) {
        	return;
        }
        else if((*tree)->MIS > data) {
                if((*tree)->left == NULL) {
                        BST temp = malloc(sizeof(Node));
                        temp->MIS = data;
                        temp->left = NULL;
                        temp->right = NULL;

			(*tree)->left = temp;

                }
		else
                	add_node(&((*tree)->left), data);
        } else {
             if((*tree)->right == NULL) {
                        BST temp = malloc(sizeof(Node));
                        temp->MIS = data;
                        temp->left = NULL;
                        temp->right = NULL;

                        (*tree)->right = temp;

                }
	     	else
                	add_node(&((*tree)->right), data);
        }
}

void insertNode(BST *tree, int data){
	if(*tree == NULL) {
		*tree = malloc(sizeof(Node));
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		(*tree)->name = NULL;
		(*tree)->MIS = data;
	} else {
		add_node(tree, data);

	}
}
*/

/*
void convertToListByInOrder(BST tree, List* list) {
        if(tree != NULL) {
		convertToListByInOrder(tree->left, list);
		enqueue(list, (void *)tree);		
		convertToListByInOrder(tree->right, list);
        }
}

void display(void *data) {
	BST tmp = ((BST)data);
	printf("\n %d", tmp->MIS);
}

List convertToList(BST tree) {
	List list;
	initList(&list);

	convertToListByInOrder(tree, &list);
	traverse(list, display);
	return list;
}
*/


