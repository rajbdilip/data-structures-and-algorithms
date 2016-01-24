#include "LinkedList.h"

void initList(LIST* mylist) {
    mylist->first = mylist->last = NULL;
    mylist->noOfNodes = 0;
}

int add(LIST* mylist, int item) {
    NODE* temp;

    if ( temp = (NODE*) malloc(sizeof(NODE)) ) {
        temp->data = item;
        temp->next = NULL;

        // If the list is null, link list to the temp node
        if (mylist->first == NULL) {
            mylist->first = mylist->last = temp;
        } else {
            mylist->last->next = temp;
            mylist->last = temp;
        }

        mylist->noOfNodes++;

        return 1;
    } else {
        printf("\nMemory Allocation Failed!");
    }

    return 0;
}

int delete(LIST* mylist, int item) {
    if (mylist->first == NULL) {
        printf("\nEmpty List!");
        return 0;
    }

    NODE* curNode = mylist->first;
    NODE* prevNode;

    while (curNode->data != item || curNode == NULL) {
        prevNode = curNode;
        curNode = curNode->next;
    }

    if (curNode == NULL) {
        printf("\nItem Not Found!");
        return 0;
    }

    // Item has been found - Delete it
    if (mylist->last == curNode) {
        prevNode->next = NULL;
        mylist->last = prevNode;
    } else {
        prevNode->next = curNode->next;
    }

    // !! Free the space used by curNode
    mylist->noOfNodes--;

    return 1;
}

void traverse(LIST* mylist) {
    if (mylist->first == NULL) {
        printf("\nEmpty List!");
        return;
    }

    NODE* n = mylist->first;

    do {
        printf("\n%d", n->data);
        n = n->next;
    } while (n != NULL);
}

void sort(LIST* mylist) {
    if (mylist->first == NULL) {
        printf("\nEmpty List!");
        return;
    }

    // Bubble Sort
    NODE* curNode = mylist->first;

    while (curNode != NULL) {
        NODE* cNode = curNode->next; // Node to be compared with curNode

        while (cNode != NULL) {
            if (curNode->data > cNode->data) {
                int temp = curNode->data;
                curNode->data = cNode->data;
                cNode->data = temp;
            }
            cNode = cNode->next;
        }
        curNode = curNode->next;
    }
}

LIST* mergeLists(LIST* list1, LIST* list2) {
    LIST* newList;
    newList = (LIST*) malloc(sizeof(LIST));

    list1->last->next = list2->first;

    newList->first = list1->first;
    newList->last = list2->last;
    newList->noOfNodes = list1->noOfNodes + list2->noOfNodes;

    return newList;
}