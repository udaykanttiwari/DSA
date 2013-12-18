#include "doublyLinkedList.h"
#include <stdlib.h>
#include <memory.h>
list *create(){
        list* start = (list*)calloc(sizeof(list),1);
        start->length = 0;
        return start;
};

node* createNode(){
        node* nodePtr = (node*)calloc(sizeof(node),1);
        return nodePtr;
}

int insertFirst(node* nodePtr,void*data,list* start){
        nodePtr->data = data;
        start->head = nodePtr;
        start->length += 1; 
        return 1;
};

int insertOnFirst(node* nodePtr,void*data,list* start){
        nodePtr->data = data;
        nodePtr->next = start->head;
        start->head = nodePtr;
        start->length += 1;
        return 1;        
};
int insertLast(node* nodePtr,void*data,list* start,node* temp){
    nodePtr->data = data;
    temp = start->head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = nodePtr;
    nodePtr->prev = temp;
    start->length += 1;
    return 1;        
}

int insertMiddle(node* nodePtr,void*data,list* start,node* temp,node* temp2,int index){
        int i;
        nodePtr->data = data;
        temp = start->head;
        for(i=1;i<index-1;i++)
                temp = temp->next;
        temp2 = temp->next;
        temp->next = nodePtr;
        nodePtr->prev = temp;
        nodePtr->next = temp2;
        temp2->prev = nodePtr;
        start->length += 1;
        return 1;        
};

int removeFirst(node*temp, list*start){
        temp = start->head;
        temp = temp->next;
        free(temp->prev);
        start->head = temp;
        start->length -= 1;
        return 1;        
}

int removeLast(node*temp, list*start){
        temp=start->head;
        while(temp->next!=NULL)
                temp=temp->next;
        temp=temp->prev;
        free(temp->next);
        start->length -= 1;
        return 1;
}

int removeMiddle(node*temp, node*temp2, list*start, int index){
        int i;
        temp = start->head;
        for(i=0;i<index-1;i++)
                temp = temp->next;
        temp2 = temp->next;
        temp = temp->prev;
        free(temp->next);
        temp->next = temp2;
        temp2->prev = temp;
        start->length -= 1;
        return 1;
}

int insert(list* start , int index , void* data){
        node* nodePtr = createNode();
        node* temp;
        node* temp2;
                if(index > start->length+1) return 0;
                if(start->head == NULL && index == 1)
                        return insertFirst(nodePtr,data,start);
                 if(index == 1)
                        return insertOnFirst(nodePtr,data,start); 
                 if(index == start->length+1)
                        return insertLast(nodePtr,data,start,temp); 
                 
                        return insertMiddle(nodePtr,data,start,temp,temp2,index);
                return 0;
}

int Remove(list* start , int index){
        node* temp ;
        node* temp2 ;
        if(start->head == NULL||index > start->length)
                return 0;
        if(index == 1)
                return removeFirst(temp,start);
         if(index == start->length)
                return removeLast(temp,start);
         
           else     return removeMiddle(temp,temp2,start,index);
        return 0;
}

int length(list* start){
        return start->length;
}

int findIndex(list* start, void* element, int elementSize){
        int i;
        node* temp;
        if(start->length == 0)
                return 0;
        temp = start->head;
        for(i=1;i<=start->length;i++){
                if(memcmp(temp->data,element,elementSize) == 0)
                        return i;
                temp=temp->next;
        }
        return 0;
};
void dispose(list *start){
    node *temp,*temp1;
    temp= start->head;
    while(temp->next!= NULL){
        temp1 =temp;
        temp =temp->next;
        free(temp1);
    };
    free(start);
};