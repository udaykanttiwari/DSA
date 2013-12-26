typedef struct node{
        void *data;
        struct node* next;
        struct node* pre;
}Node;

typedef struct{
        Node* head;
        int length;
}List;

typedef struct iterator{
        int (*hasNext)(struct iterator* it);
        void* (*next)(struct iterator* it);
        List* list;
        int currentPosition;
}Iterator;

List* create();
int insert(List* , int , void*);
int Remove(List* , int index);
int findIndex(List*, void*,int);
int length(List*);
void dispose(List* start);
Iterator* getIterator(List* list);
int hasNext(Iterator* iterator);
void* next(Iterator* iterator);
