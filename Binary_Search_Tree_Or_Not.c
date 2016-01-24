/*
 * Check if a Tree is Binary Search Tree
 */
 
#include <stdio.h>
#include <stdlib.h>

#define LEFT 10
#define RIGHT 11

int index;

typedef struct node {
	struct node* left;
	struct node* right;
	int data;
} NODE;

typedef struct tree {
	NODE* root;
} TREE;

void insert(TREE*, int);
void inorder(NODE*, int*);
int isSorted(int*, int);

int main() {

	TREE* mytree = (TREE*) malloc(sizeof(TREE));
	mytree->root = NULL;
	
	int numbers[10] = {5, 4, 8, 7, 10, 3, 9, 1, 6, 2};
	int counter;
	
	for (counter = 0; counter < 10; counter++)
	    insert(mytree, numbers[counter]);

	int numbers2[10];
	int index;
	inorder(mytree->root, numbers2);
	
	if ( isSorted(numbers2, 10) )
		printf("\n\nIt is a Binary Search Tree");
	else
	    printf("\n\nIt is NOT a Binary Search Tree");
	
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

void inorder(NODE* mynode, int* arr) {
	if (mynode != NULL) {
		inorder(mynode->left, arr);
		arr[index++] = mynode->data;
		inorder(mynode->right, arr);
	}
}

int isSorted(int* arr, int size) {
	int counter;
	int prev = arr[0];
	
	for (counter = 1; counter < size; counter++) {
		if (arr[counter] < prev)
		    return 0;
	}
	
	return 1;
}