/*
 * Implementation of a Binary Search Tree and it's traversals
 */

#include <stdio.h>
#include <stdlib.h>

#define PRE_ORDER 0
#define POST_ORDER 1
#define IN_ORDER 2

#define LEFT 10
#define RIGHT 11

typedef struct node {
	struct node* left;
	struct node* right;
	int data;
} NODE;

typedef struct tree {
	NODE* root;
} TREE;

void insert(TREE*, int);
void traverse(TREE*, int);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);

int main() {

	TREE* mytree = (TREE*) malloc(sizeof(TREE));
	mytree->root = NULL;

	int numbers[10] = {5, 4, 8, 7, 10, 3, 9, 1, 6, 2};
	int counter;

	for (counter = 0; counter < 10; counter++)
	    insert(mytree, numbers[counter]);

	printf("PRE-ORDER: ");
	traverse(mytree, PRE_ORDER);
	printf("IN-ORDER: ");
	traverse(mytree, IN_ORDER);
	printf("POST-ORDER: ");
	traverse(mytree, POST_ORDER);

	getch();

	return 0;
}

void insert(TREE* mytree, int item) {

	NODE* temp = (NODE*) malloc(sizeof(NODE));
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;

	if (mytree->root == NULL) {
		mytree->root = temp;
		return;
	}

	NODE* currentNode = mytree->root;
	NODE* prevNode;
	int position;

	do {
		prevNode = currentNode;
		if (item > currentNode->data) {
		    position = RIGHT;
		    currentNode = currentNode->right;
		} else {
	    	position = LEFT;
	    	currentNode = currentNode->left;
		}
	} while ( currentNode != NULL);

	if (position == RIGHT)
		prevNode->right = temp;
	else
		prevNode->left = temp;

}

void traverse(TREE* mytree, int order) {
	if (order == PRE_ORDER)
		preorder(mytree->root);
	else if (order == IN_ORDER)
	    inorder(mytree->root);
	else if (order == POST_ORDER)
	    postorder(mytree->root);

	printf("\n");
}

void preorder(NODE* mynode) {
	if (mynode != NULL) {
		printf(" %d ", mynode->data);
		preorder(mynode->left);
		preorder(mynode->right);
	}
}

void inorder(NODE* mynode) {
	if (mynode != NULL) {
		inorder(mynode->left);
		printf(" %d ", mynode->data);
		inorder(mynode->right);
	}
}

void postorder(NODE* mynode) {
	if (mynode != NULL) {
		postorder(mynode->left);
		postorder(mynode->right);
		printf(" %d ", mynode->data);
	}
}