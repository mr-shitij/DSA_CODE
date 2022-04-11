#include<stdio.h>
#include<stdlib.h>
#include"BST.h"
#include"LinkList.h"


void initBST(BST *tree) {
	*tree = NULL;
}

void insertNode(BST *tree, int data) {
	if(*tree == NULL) {
		*tree = malloc(sizeof(Node));
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		(*tree)->name = NULL;
		(*tree)->MIS = data;
		
	}
	else if((*tree)->MIS == data) {
		return;
	}
	else if((*tree)->MIS > data) {
		insertNode(&((*tree)->left), data);
	}
	else if((*tree)->MIS < data) {
		insertNode(&((*tree)->right), data);
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
		printf("\n %d", tree->MIS);
		inorder(tree->right);
        }
}

void preorder(BST tree) {
        if(tree != NULL) {
		printf("\n %d", tree->MIS);
		preorder(tree->left);
		preorder(tree->right);
        }
}

void postorder(BST tree) {
	if(tree != NULL) {
		postorder(tree->left);
		postorder(tree->right);
		printf("\n %d", tree->MIS);
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

void display(void *data) {
	printf("\n %d", *((int*)data));
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
	printf("H1 \n");
	if(tree != NULL) {
		printf("H2 \n");
		BST parentNode = *tree;
		BST crrentNode = *tree;
		printf("H3 \n");
		while(crrentNode != NULL) {
			printf("H4 \n");
			if(crrentNode->MIS == MIS) {
				break;
			}
			printf("H5 \n");
			parentNode = crrentNode;
			if(crrentNode->MIS < MIS) {
				crrentNode = crrentNode->right;
			}
			else {
				crrentNode = crrentNode->left;
			}
			printf("H6 \n");
		}
		printf("H7 \n");
		if(crrentNode == NULL) {
			return;
		}
		printf("H8 \n");
		
		/* Node with 0 child */
		if(crrentNode->left == NULL && crrentNode->right == NULL) {
			printf("H9 \n");
			if(parentNode->left == crrentNode) {
				parentNode->left = NULL;
			}
			else {
				parentNode->right = NULL;				
			}
			free(crrentNode);
			crrentNode = NULL;
			return;
		}
		
		printf("H10 \n");
		/* Node with 1 child */
		if(crrentNode->left != NULL && crrentNode->right == NULL) {
			printf("H11 \n");
			if(parentNode->left == crrentNode) {
				parentNode->left = crrentNode->left;
			}
			else {
				parentNode->right = crrentNode->left;
			}
			free(crrentNode);
			crrentNode = NULL;
			return;
		}
		else if(crrentNode->left == NULL && crrentNode->right != NULL) {
			printf("H12 \n");
			if(parentNode->right == crrentNode) {
				parentNode->left = crrentNode->right;
			}
			else {
				parentNode->right = crrentNode->right;
			}
			free(crrentNode);
			crrentNode = NULL;
			return;
		}

		printf("H13 \n");
		/* Node with 2 child */
		if(crrentNode->left != NULL && crrentNode->right != NULL) {
			// Find the minimum node from the right subtree
			BST parentOfMinNode = NULL;
			BST minNode = crrentNode->right;
			
			printf("H14 \n");
			while(minNode->left != NULL) {
				parentOfMinNode = minNode;
				minNode = minNode->left;
			}
			if(parentOfMinNode != NULL)
				parentOfMinNode->left = minNode->right;
			
			
			printf("H15 \n");
						
			if(parentNode->left == crrentNode) {
				parentNode->left = minNode;
			}
			else {
				parentNode->right = minNode;
			}

			printf("H16 \n");
			minNode->left = crrentNode->left;
			minNode->right = crrentNode->right;
			free(crrentNode);
			crrentNode = NULL;
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
		if(level == 0) {
			printf("\n %d", tree->MIS);
			return;
		}
	
		int currentLevel = 0;
		List queue;
		initList(&queue);

		BST current = tree;
		enqueue(&queue, (void *)current);


		while(currentLevel != level) {
			BST temp = (BST)queue->data;
			dequeue(&queue);

			currentLevel++;

			enqueue(&queue, (void *)temp->left);
			enqueue(&queue, (void *)temp->right);
		}

		traverse(queue, display);
		
		printf("H6\n");
		int power = powerFunc(2, level);
		printf("\n POWER : %d", power);
		for(int iterator = 0; iterator <= power; iterator++) {
			printf("H7\n");
			BST temp = (BST)peek(queue);
			dequeue(&queue);

			printf("H8\n");

			if(temp != NULL)
				printf("\n %d", temp->MIS);
			printf("H9\n");
		}		
		
	}
}
*/



/*
void Display_Level(BST tree, int level) { // Level Wise traversal
	if(tree != NULL) {

		int currentLevel = 0, flag = 0, enqueueFlag = 0;

		BST iterator = NULL;
		List list;
		initList(&list);
		enqueue(&list, (void *)tree);

		while(list != NULL) {
			iterator = ((BST)list->data);
			if(iterator->left != NULL && enqueueFlag == 0) {
				enqueue(&list, (void *)iterator->left);

				currentLevel++;
				flag = 1;
			}
			
			if(iterator->right != NULL && enqueueFlag == 0) {
				enqueue(&list, (void *)iterator->right);
				if(flag == 0)
					currentLevel++;
			}
			
			if(currentLevel == level) {
				printf("\n %d", iterator->MIS);
				enqueueFlag++;
			}
			dequeue(&list);
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


