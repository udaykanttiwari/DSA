typedef struct Node{
    void *data;
    struct Node* next;
    struct Node* pre; //change pre to prev
}node; //starting of own define data type from Upper Case;

typedef struct{
        node* head;
        int length;
}list;

list* create();
int insert(list* , int , void*);
int remove(list* , int index); 
int findIndex(list*, void*,int);
int length(list*);
int insertOnFirst(node* nodePtr,void*data,list* start);
int insertFirst(node* nodePtr,void*data,list* start);
int insertMiddle(node* nodePtr,void*data,list* start,node* temp,node* temp2,int index);
int insertLast(node* nodePtr,void*data,list* start,node* temp);
int removeFirst(node*temp, list*start);
int removeLast(node*temp, list*start);
int removeMiddle(node*temp, node*temp2, list*start, int index);
int insert(list* start , int index , void* data);
int Remove(list* start , int index);
int length(list* start);
int findIndex(list* start, void* element, int elementSize);