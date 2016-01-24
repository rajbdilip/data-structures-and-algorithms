/*
 * Reverse a string using a stack
 */

#include <stdio.h>

struct stack {
    char chars[50];
    int top;
};

typedef struct stack STACK;

void push(STACK*, int);
char pop(STACK*);
int isempty(STACK*);

int main() {

    STACK* mystack = ( STACK* ) malloc( sizeof( STACK ) );
    mystack->top = 0;

    char string[50];
    char reversed_string[50];

    printf("Enter a string:\t\t ");
    gets(string);

    int i = 0;

    // Fill the stack
    while (string[i] != '\0') {
        push( mystack, *(string + i++) );
    }

    // Empty the stack to get the reversed string
    i = 0;
    while ( !isempty(mystack) ) {
        reversed_string[i++] = pop(mystack);
    }
    reversed_string[i] = '\0';

    printf("Reversed String:\t ");
    puts(reversed_string);

    return 0;
}

void push( STACK *mystack, int item ) {
    mystack->chars[mystack->top++] = item;
}

char pop( STACK *mystack ) {
    return mystack->chars[--mystack->top];
}

int isempty( STACK *mystack ) {
    if ( mystack->top < 0 )
        return 1;
    return 0;
}