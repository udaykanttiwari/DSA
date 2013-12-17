#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
        void *data;
        int priority;
        struct Node* next;
}node;

typedef struct{
        node* head;
        int length;
}list;

list* create();
int enqueue(list*,int priority,void* data);
int dequeue(list*);