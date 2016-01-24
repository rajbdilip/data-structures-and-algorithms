/*
 * Check whether a string is palindrome using two way linked list.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char item;
    struct node* left;
    struct node* right;
} NODE;

typedef struct list {
    NODE* left;
    NODE* right;
} LIST;

void initList(LIST*);
void add(LIST*, char);
char* getReverseString(LIST*);

int main() {

    char string[50];
    char revString[50];

    printf("Enter a string: ");
    scanf("%s", string);

    LIST* mylist = (LIST*) malloc(sizeof(LIST));
    initList(mylist);

    int counter = 0;

    while (string[counter] != '\0')
        add(mylist, string[counter++]);

    //puts(getReverseString(mylist));
    if ( strcmp(string, getReverseString(mylist)) == 0 )
        printf("\nPalindrome");
    else
        printf("\nNot Palindrome");

    return 0;
}

void initList(LIST* mylist) {
    mylist->left = mylist->right = NULL;
}

void add(LIST* mylist, char item) {
    NODE* temp = (NODE*) malloc(sizeof(NODE));

    temp->item = item;

    if (mylist->left == NULL) {
        temp->left = temp->right = NULL;
        mylist->left = mylist->right = temp;
    } else {
        NODE *lastNode = mylist->right;
        temp->right = NULL;
        lastNode->right = temp;
        temp->left = lastNode;
        mylist->right = temp;
    }
}

char* getReverseString(LIST* mylist) {
    if (mylist->left == NULL) {
        printf("\nEmpty List!");
        return;
    }

    char* string;
    int counter = 0;

    NODE* curNode;
    curNode = mylist->right;

    do {
        *(string + counter++) = curNode->item;
        curNode = curNode->left;
    } while (curNode != NULL);

    *(string + counter) = '\0';

    return string;
}