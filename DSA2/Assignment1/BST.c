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

void search(BST tree, int MIS) { // to recursively search for a node with the given key.
	if(tree != NULL) {
		if(tree->MIS == MIS) {
			printf("\n DATA FOUND : %d", MIS);
		}
		else if(tree->MIS > MIS) {
			search(tree->right, MIS);
		}
		else {
			search(tree->right, MIS);
		}
		
	}
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


// Problem
void Display_Level(BST tree, int level) { // Level Wise traversal
	if(tree != NULL) {
		int currentLevel = -1, flag = 0, enqueueFlag = 0;

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

void removeNode() {

}

void destoryTree() {

}


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


