#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
        void *data;
        struct Node* next;
        struct Node* pre;
}node;

typedef struct{
        node* head;
        int length;
}list;

list* create();
int insert(list* start , int index , void* data);
int Remove(list* start , int index);
int length(list* start);
int findIndex(list* start, void* element, int elementSize);