#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"BST.h"
#include"Stack.h"


void initBST(BST *tree) {
	*tree = NULL;
}
/*
private void postorder(Node head) {
  if (head == null) {
    return;
  }
  LinkedList<Node> stack = new LinkedList<Node>();
  stack.push(head);

  while (!stack.isEmpty()) {
    Node next = stack.peek();

    boolean finishedSubtrees = (next.right == head || next.left == head);
    boolean isLeaf = (next.left == null && next.right == null);
    if (finishedSubtrees || isLeaf) {
      stack.pop();
      System.out.println(next.value);
      head = next;
    }
    else {
      if (next.right != null) {
        stack.push(next.right);
      }
      if (next.left != null) {
        stack.push(next.left);
      }
    }
  }
}
*/

void generateFromTree(BST *tree, int data[], int end) {
	if(*tree == NULL){
		return;
	}
	StackList stack;
	initStack(&stack); 
	
	push(&stack, (void *) tree);
	while(stack != NULL) {
		BST node = (BST) peek(stack);
		int finishedSubtree = ( node->right == *tree || node->left == *tree );
		int isLeaf = ( node->left == NULL && node->right == NULL );
		if(finishedSubtree || isLeaf) {
			pop(&stack);
			printf("\n %d", node->MIS);
			*tree = node;
		}
		else {
			if(node->right != NULL) {
				push(&stack, node->right);
			}
			if(node->left != NULL) {
				push(&stack, node->left);
			}
		}
	}
}

/*
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
*/

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


