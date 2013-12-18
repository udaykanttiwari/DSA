typedef struct Node{
    void *data;
    struct Node* next;
    struct Node* prev; 
}node; 
typedef struct{
        node* head;
        int length;
}list;

list* create();
int insert(list* , int , void*);
int findIndex(list*, void*,int);
int insert(list* start , int index , void* data);
int Remove(list* start , int index);
void dispose(list *);
