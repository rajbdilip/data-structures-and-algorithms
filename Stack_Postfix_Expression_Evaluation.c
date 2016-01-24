/*
 * Evaluate a given postfix expression using a stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct stack {
    int items[100];
    int top;
};

typedef struct stack STACK;

void push(STACK*, int);
int pop(STACK*);

int main() {

    STACK mystack;
    mystack.top = 0;

    char postfix_expression[100];
    printf("Enter a postfix expression to be evaluated\n: ");
    gets(postfix_expression);

    int i = 0, j = 0;

    while ( postfix_expression[i] != '\0' ) {
        char c = postfix_expression[i++];
        char accum[6];

        if ( c == '^' || c == '*' || c == '/' || c == '+' || c == '-' ) {   // OPERATOR

            // Pop out top two items from the stack, evauluate them with the operator and push the result
            int a = pop(&mystack);
            int b = pop(&mystack);
            printf("\npop\t%d\npop\t%d", a, b);
            int r;

            switch (c) {
                case '^': { r = pow(b, a); break;}
                case '*': { r = b*a; break;}
                case '/': { r = b/a; break;}
                case '+': { r = b+a; break;}
                case '-': { r = b-a; break;}
            }

            push(&mystack, r);

        } else if ( c == ',') {
            // Push from accumulator to the stack
            if ( j > 0 ) {
                accum[j++] = '\0';
                push( &mystack, atoi(accum) );
                //accum[0] = '\0';
                j = 0;
            }
        } else {    // OPERAND
            // Accumulate
            accum[j++] = c;
        }
    }

    // Pop out from the stack
    printf("\n\nResult: %d", pop(&mystack));

    return 0;
}

void push( STACK *mystack, int item ) {
    mystack->items[mystack->top++] = item;
    printf("\npush\t%d", item);
}

int pop( STACK *mystack ) {
    return mystack->items[--mystack->top];
}