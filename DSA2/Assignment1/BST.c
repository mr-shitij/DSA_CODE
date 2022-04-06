#include<stdio.h>
#include<stdlib.h>
#include"BST.h"

typedef struct Node {
	struct Node* left;
	struct Node* right;
	int MIS;
	char *name;
}Node;
typedef Node* BST;


void initBST(BST *tree) {
	*tree = NULL;
}

void add_node(BST *tree, int data) {

        if((*tree)->MIS > data) {

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

void removeNode() {

}

void search(BST tree) {
	if(tree->MIS ==) {
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

void inorder(BST tree) {
        if(tree != NULL) {
                inorder(tree->left);
		printf("\n %d", tree->MIS);
                inorder(tree->right);
        }
}

void Display_Level() {

}

void destoryTree() {

}

int main() {
	BST tree;
	initBST(&tree);
	int i = 0, data;
	do {
		printf("\n 1.Insert");
		printf("\n 2.PreOrder");
	        printf("\n 3.InOrder");
                printf("\n 4.PostOrder");
		printf("\n 5.Exit");
		printf("\n Select Choice : ");
		scanf("%d", &i);
		
		switch(i) {
			case 1:
				printf("\n Enter the data : ");
				scanf("%d", &data);
				insertNode(&tree, data);
				break;
			case 2:
				preorder(tree);
				break;
		
	                case 3:
                                inorder(tree);
                                break;
                        case 4:
                                postorder(tree);
                                break;

		}


	} while (i != 5);
	return 0;
}
