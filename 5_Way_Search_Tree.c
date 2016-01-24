/*
 * Implementation of a 5-Way Search Tree
 *
 * Same code can be modified to creat any other M-way tree
 */

#include <stdio.h>
#include <stdlib.h>

#define LEFT 0;
#define RIGHT 1;

typedef struct node {
	struct node* links[5];
	int data[4];
	int index;
} NODE;

typedef struct tree {
	NODE* root;
} TREE;

void initNode(NODE*);
void insert(TREE*, int);
void inorder(NODE*);
void sort(int*, int);
void traverseNode(NODE*);

int main() {

	TREE* mytree = (TREE*) malloc(sizeof(TREE));
	mytree->root = NULL;

	int numbers[20] = {2, 5, 13, 8, 1, 18, 15, 16, 11, 3, 9, 19, 14, 20, 17, 7, 6, 12, 10, 4};
	int counter;

	for (counter = 0; counter < 20; counter++)
		insert(mytree, numbers[counter]);

	printf("\n\n");

	printf("\nIN-ORDER:\t");
	inorder(mytree->root);

	getch();
	return 0;
}

void initNode(NODE* mynode) {
	int i;
	for (i = 0; i < 5; i++)
	    mynode->links[i] = NULL;

	mynode->index = 0;
}

void insert(TREE* mytree, int item) {

	if (mytree->root == NULL ) {
		NODE* temp = (NODE*) malloc(sizeof(NODE));
		initNode(temp);
		temp->data[temp->index++] = item;

		mytree->root = temp;

		printf("\nRoot created!");
		return;
	}

	NODE* curNode = mytree->root;
	NODE* prevNode;
	int link;

	do {
		if (curNode->index < 4) {
			curNode->data[curNode->index++] = item;
			sort(curNode->data, curNode->index);
			printf("\nInserted in existing node!");
			return;
		} else {

			// Find the link position to the new node
			int cnt;
			link = -1;      // Reset positon
			for (cnt = 0; cnt < 4; cnt++) {
				if (item <= curNode->data[cnt]) {
				    link = cnt;
					break;
				}
			}

			if (link == -1)
			    link = 4;

			// New node to be inserted in
			prevNode = curNode;
			curNode = curNode->links[link];
		}

	} while ( curNode != NULL);

	// A new node is to be created
	NODE* temp = (NODE*) malloc(sizeof(NODE));
	initNode(temp);
	temp->data[temp->index++] = item;

	// Link new node
	prevNode->links[link] = temp;

	printf("\nNew Root created!");

}

void inorder(NODE* mynode) {
	if (mynode != NULL) {
		int i;
		for (i = 0; i < mynode->index; i++) {
            inorder(mynode->links[i]);
			printf("%d ", mynode->data[i]);
		}

		inorder(mynode->links[mynode->index]);
	}
}

void sort(int* list, int size) {

	int i, j;

	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1; j++) {
			if ( list[j] > list[j + 1]) {
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;

			}
		}
	}
}

void traverseNode(NODE* mynode) {
	if (mynode != NULL) {
		int i;
		for (i = 0; i < mynode->index; i++)
		    printf("%d ", mynode->data[i]);
	}

}