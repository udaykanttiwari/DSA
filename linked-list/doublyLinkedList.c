#include "doublyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

List *create(){
        List* start = (List*)calloc(sizeof(List),1);
        start->length = 0;
        return start;
};

Node* createNode(){
        Node* nodePtr = (Node*)calloc(sizeof(Node),1);
        return nodePtr;
}

int insertFirst(Node* nodePtr,void*data,List* start){
        nodePtr->data = data;
        start->head = nodePtr;
        start->length += 1; 
        return 1;
};

int insertOnFirst(Node* nodePtr,void*data,List* start){
        nodePtr->data = data;
        nodePtr->next = start->head;
        start->head = nodePtr;
        start->length += 1;
        return 1;        
}

int insertLast(Node* nodePtr,void*data,List* start,Node* temp){
        nodePtr->data = data;
        temp->next = start->head;
        while(temp->next!=NULL)
                temp = temp->next;
        temp->next = nodePtr;
        nodePtr->pre = temp;
        start->length += 1;
        return 1;        
}

int insertMiddle(Node* nodePtr,void*data,List* start,Node* temp,Node* temp2,int index){
        int i;
        nodePtr->data = data;
        temp = start->head;
        for(i=1;i<index-1;i++)
                temp = temp->next;
        temp2 = temp->next;
        temp->next = nodePtr;
        nodePtr->pre = temp;
        nodePtr->next = temp2;
        temp2->pre = nodePtr;
        start->length += 1;
        return 1;        
}

int removeFirst(Node*temp, List*start){
        temp = start->head;
        temp = temp->next;
        free(start->head);
        start->head = temp;
        start->length -= 1;
        return 1;        
}

int removeLast(Node*temp, List*start){
        temp=start->head;
        while(temp->next!=NULL)
                temp=temp->next;
        temp=temp->pre;
        free(temp->next);
        start->length -= 1;
        return 1;
}

int removeMiddle(Node*temp, Node*temp2, List*start, int index){
        int i;
        temp = start->head;
        for(i=0;i<index-1;i++)
                temp = temp->next;
        temp2 = temp->next;
        temp = temp->pre;
        free(temp->next);
        temp->next = temp2;
        temp2->pre = temp;
        start->length -= 1;
        return 1;
}

int insert(List* start , int index , void* data){
        Node* nodePtr = createNode();
        Node* temp = createNode();
        Node* temp2 = createNode();        
        if(index > start->length+1) return 0;
        if(start->head == NULL && index == 1)
                return insertFirst(nodePtr,data,start);
        if(index == 1)
                return insertOnFirst(nodePtr,data,start); 
        if(index == start->length+1)
                return insertLast(nodePtr,data,start,temp); 
        return insertMiddle(nodePtr,data,start,temp,temp2,index);
}

int Remove(List* start , int index){
        Node* temp;
        Node* temp2;
        if(start->head == NULL||index > start->length)
                return 0;
        if(index == 1)
                return removeFirst(temp,start);
        if(index == start->length)
                return removeLast(temp,start);
        return removeMiddle(temp,temp2,start,index);
}

int length(List* start){
        return start->length;
}

int findIndex(List* start, void* element, int elementSize){
        int i;
        Node* temp;
        if(start->length == 0)
                return 0;
        temp = start->head;
        for(i=1;i<=start->length;i++){
                if(memcmp(temp->data,element,elementSize) == 0)
                        return i;
                temp=temp->next;
        }
        return 0;
}

int hasNext(Iterator* iterator){
        if(iterator->list->length == iterator->currentPosition)
                return 0;
        return 1;
}

void* next(Iterator* iterator){
        int count = 0;
        Node* temp = iterator->list->head;
        if(hasNext(iterator) == 0)return NULL;
        for(count=0;count<=iterator->currentPosition-1;count++){
                temp = temp->next;
        };
        ++iterator->currentPosition;
        return temp->data;
}

Iterator* getIterator(List* list){
        Iterator* iterator = (Iterator*)calloc(sizeof(Iterator),1);
        iterator->currentPosition = 0;
        iterator->list = list;
        iterator->hasNext = hasNext;
        iterator->next =  next;
        return iterator;

}

void dispose(List* start){
        Node* temp;
        Node* temp2;
        temp = start->head;
        while(temp->next != NULL){
        temp2 = temp;
        temp = temp->next;
        free(temp2);
};
        free(temp);
}