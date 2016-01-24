/*
 * Store two polynomials using linked list and perform subtraction on them
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int co;
    int exp;
    struct node* next;
};

struct list {
    struct node* first;
    struct node* last;
};

typedef struct node NODE;
typedef struct list LIST;

void initList(LIST*);
int add(LIST*, int, int);
void traverse(LIST*);
LIST *subtract(LIST*, LIST*);

int main() {

    LIST *pol1, *pol2;
    pol1 = (LIST*) malloc(sizeof(LIST));
    pol2 = (LIST*) malloc(sizeof(LIST));

    initList(pol1);
    initList(pol2);

    printf("POLYNOMIAL 1:\n\n");
    printf("Coefficient of:\n");

    int counter, coefficient;

    for (counter = 3; counter >= 0; counter--) {

        printf("\tx^%d: ", counter);
        scanf("%d", &coefficient);

        add(pol1, coefficient, counter);
    }

    printf("POLYNOMIAL 2:\n\n");
    printf("Coefficient of:\n");

    for (counter = 3; counter >= 0; counter--) {
        int coefficient;
        printf("\tx^%d: ", counter);
        scanf("%d", &coefficient);

        add(pol2, coefficient, counter);
    }

    LIST *newPol = subtract(pol1, pol2);

    traverse(pol1);
    traverse(pol2);

    traverse(newPol);

    return 0;
}

void initList(LIST* mylist) {
    mylist->first = mylist->last = NULL;
}

int add(LIST* mylist, int coefficient, int exponent) {
    NODE* temp;

    if ( temp = (NODE*) malloc(sizeof(NODE)) ) {
        temp->co = coefficient;
        temp->exp = exponent;
        temp->next = NULL;

        // If the list is null, link list to the temp node
        if (mylist->first == NULL) {
            mylist->first = mylist->last = temp;
        } else {
            mylist->last->next = temp;
            mylist->last = temp;
        }

        return 1;
    } else {
        printf("\nMemory Allocation Failed!");
    }

    return 0;
}

LIST* subtract(LIST* mylist1, LIST* mylist2) {
    LIST *newList = (LIST*) malloc(sizeof(LIST));

    initList(newList);

    NODE *node1, *node2;
    node1 = mylist1->first;
    node2 = mylist2->first;

    do {
        add(newList, node1->co - node2->co, node1->exp );
        node1 = node1->next;
        node2 = node2->next;
    } while (node1 != NULL);

    return newList;

}

void traverse(LIST* mylist) {
    if (mylist->first == NULL) {
        printf("\nEmpty List!");
        return;
    }

    int first = 1;
    NODE *n = mylist->first;

    do {
        if (n->co != 0) {
            if (first == 1) {

                if (n->exp == 1)
                    printf("%dx ", n->co);
                else if (n->exp == 0)
                    printf("%d ", n->co);
                else if (n->co == 1)
                    printf("x^%d ", n->exp);
                else
                    printf("%dx^%d ", n->co, n->exp);

                first = 0;
            } else {
                if (n->exp == 1)
                    printf("+ %dx ", n->co);
                else if (n->exp == 0)
                    printf("+ %d ", n->co);
                else if (n->co == 1)
                    printf("+ x^%d ", n->exp);
                else
                    printf("+ %dx^%d ", n->co, n->exp);
            }
        }
        n = n->next;
    } while (n != NULL);

    printf("\n");
}