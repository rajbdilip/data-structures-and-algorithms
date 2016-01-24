/*
 * Implementation of a queue using an array
 */

#include <stdio.h>
#define MAX_SIZE 10

const int null = -1;

struct queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

typedef struct queue QUEUE;

void enqueue(QUEUE*, int);
void dequeue(QUEUE*);
void display(QUEUE*);

int main() {

    QUEUE myqueue;
    myqueue.front = null;
    myqueue.rear = null;

    int choice;

    printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int item;
                printf("\nEnter an item to enqueue: ");
                scanf("%d", &item);

                enqueue( &myqueue, item );
                break;
            }

            case 2: {   // DEQUEUE
                dequeue(&myqueue);
                break;
            }

            case 3: {   // DISPLAY
                display(&myqueue);
                break;
            }
        }

    } while ( choice < 4 && choice > 0 );

    return 0;
}

void enqueue(QUEUE *myqueue, int item) {
    // Check if the queue is full
    if ( (myqueue->front == 0 && myqueue->rear == MAX_SIZE - 1)
        || myqueue->front == myqueue->rear + 1) {
        printf("\nSTACK OVERFLOW!");
        return;
    }

    // Find the new position of rear
    if (myqueue->front == null && myqueue->rear == null) {
        printf("null\n");
        myqueue->front = myqueue->rear = 0;
    } else if (myqueue->rear == MAX_SIZE - 1) {
        myqueue->rear = 0;
    } else {
        myqueue->rear++;
    }

    myqueue->items[myqueue->rear] = item;
    printf("Front: %d\nRear: %d\n", myqueue->front, myqueue->rear);
}

void dequeue(QUEUE *myqueue) {
    // Check for underflow
    if (myqueue->front == null) {
        printf("\nSTACK UNDERFLOW");
        return;
    }

    int item = myqueue->items[myqueue->front];
    printf("Dequeued: %d", item);

    // Find new Front
    if (myqueue->front == myqueue->rear) {
        myqueue->front = myqueue->rear = null;
    } else if (myqueue->front == MAX_SIZE - 1) {
        myqueue->front = 0;
    } else {
        myqueue->front++;
        printf("here");
    }

    printf("\nFront: %d\nRear: %d\n", myqueue->front, myqueue->rear);

}

void display(QUEUE *myqueue) {
    int i;
    for (i = 0; i < MAX_SIZE; i++)
        printf("\n%d", myqueue->items[i]);
}