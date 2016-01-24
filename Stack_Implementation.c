/*
 * Implementation of a stack using an array
 */

#include <stdio.h>
#define MAX_SIZE 10

struct stack {
    int items[MAX_SIZE];
    int top;
};

typedef struct stack STACK;

void push(STACK*, int);
void pop(STACK*);
void peep(STACK*);
int isempty(STACK*);
int isfull(STACK*);

int main() {

    STACK mystack;
    mystack.top = 0;

    int choice;

    printf("\n\n");
    printf("1. PUSH\n2. POP\n3. PEEP\n4. EXIT\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {   // PUSH
                int item;
                printf("\nEnter an item to push: ");
                scanf("%d", &item);

                push( &mystack, item );
                break;
            }

            case 2: {   // POP
                pop(&mystack);
                break;
            }

            case 3: {   // PEEP
                peep(&mystack);
                break;
            }
        }
    } while ( choice < 4 && choice > 0 );

    return 0;
}

void push( STACK* mystack, int item ) {
    if ( !isfull(mystack) ) {
        mystack->items[mystack->top++] = item;
        printf("\nPush Operation Successfull!");
    } else {
        printf("\nStack Overflow!");
    }
}

void pop( STACK *mystack ) {
    if ( !isempty(mystack) )
        printf("\nPOPPED: %d", mystack->items[--mystack->top]);
    else
        printf("\nStack Underflow!");
}

void peep( STACK *mystack ) {
    int i;

    for ( i = (mystack->top - 1); i >= 0; i-- )
        printf("\n%d", mystack->items[i]);
}

int isfull( STACK *mystack ) {
    if ( mystack->top == MAX_SIZE )
        return 1;
    return 0;
}

int isempty( STACK *mystack ) {
    if ( mystack->top < 0 )
        return 1;
    return 0;
}