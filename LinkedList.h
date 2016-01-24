#ifndef LINKED_LIST
#define LINKED_LIST

struct node {
    int data;
    struct node* next;
};

struct list {
    struct node* first;
    struct node* last;
    int noOfNodes;
};

typedef struct node NODE;
typedef struct list LIST;

void initList(LIST*);
int add(LIST*, int);
int delete(LIST*, int);
void traverse(LIST*);
void sort(LIST*);
LIST* mergeLists(LIST*, LIST*);

#endif // LINKED_LIST