/*
 *  Store a sparse matrix in a header linked list.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int row;
	int col;
	int value;
	struct Node* next;
} NODE;

typedef struct list {
	NODE* first;
	NODE* last;
	int rows;
	int cols;
	int noOfElements;
} LIST;

void add(LIST*, int, int, int);
void display(LIST*);

int main() {

	int matrix[4][4] = {
		{0, 1, 0, 2},
		{0, 0, 0, 3},
		{5, 0, 0, 7},
		{0, 0, 9, 0},
	};

	LIST *mylist = (LIST*) malloc(sizeof(LIST));
	mylist->first = NULL;
	mylist->last = NULL;
	mylist->noOfElements = 0;

	int rCount, cCount, count = 0;

	for (rCount = 0; rCount < 4; rCount++) {
		for (cCount = 0; cCount < 4; cCount++) {
			if (matrix[rCount][cCount] != 0) {
				add(mylist, rCount, cCount, matrix[rCount][cCount]);
				count++;
			}
		}
	}

	mylist->cols = cCount++;
	mylist->rows = rCount++;

	printf("Dimension: %d x %d\n", mylist->rows, mylist->cols);
	printf("Number of non-zero elements: %d\n\n", mylist->noOfElements);
	display(mylist);
	getch();
	return 0;
}

void add(LIST* mylist, int row, int col, int val) {
	NODE* temp = (NODE*) malloc(sizeof(NODE));

	temp->row = row;
	temp->col = col;
	temp->value = val;
	temp->next = NULL;

	if (mylist->first == NULL) {
		mylist->first = mylist->last = temp;
	} else {
		mylist->last->next = temp;
		mylist->last = temp;
	}

	mylist->noOfElements++;
}

void display(LIST* mylist) {

	if (mylist->first == NULL) {
		printf("\nEmpty List!");
		return;
	}

	NODE* curNode = mylist->first;

	printf("Row\tColumn\tValue\n");
	printf("---\t-----\t-----\n");

	do {
		printf("%d\t%d\t%d\n", curNode->row, curNode->col, curNode->value);
		curNode = curNode->next;
	} while (curNode != NULL);

}