#include "priorityQueue.h"
int addFirst(node *nodePtr,list *listPtr,void *data,int priority,node *temp);
int addFirstNode(node *nodePtr,list *listPtr,void *data,int priority);
list* create(){
        list* listPtr = (list*)calloc(sizeof(list),1);
        return listPtr;
};
void createNode(node *temp,void* data,int priority){
        temp->data = data;
        temp->priority = priority;
};
int addFirstNode(node *nodePtr,list *listPtr,void *data,int priority){
        createNode(nodePtr,data,priority);
        listPtr->head = nodePtr;
        listPtr->length +=1;
        return 1; 
}
int addFirst(node *nodePtr,list *listPtr,void *data,int priority,node *temp){
        nodePtr->next = temp;
        listPtr->head = nodePtr;
        listPtr->length +=1;
        return 1;  
};

int addInLast(node *nodePtr,list *listPtr,void *data,int priority,node *temp){
        temp->next = nodePtr;
        listPtr->length +=1;
        return 1;        
};
int addInMiddle(node *nodePtr,list *listPtr,void *data,int priority,node *temp,node* temp2){
        temp = listPtr->head;
        while(temp->priority < nodePtr->priority){
                temp2=temp;
                temp=temp->next;
        };
        temp2->next = nodePtr;
        nodePtr->next=temp;
        listPtr->length +=1;
                return 1;        
};


int enqueue(list* listPtr,int priority,void* data){
        node* nodePtr = calloc(sizeof(node),1);
        node *temp=calloc(sizeof(node),1);
        node *temp2=calloc(sizeof(node),1);
        if(listPtr->length == 0){                
            return addFirstNode(nodePtr,listPtr,data,priority);
        };
        createNode(nodePtr,data,priority);
        temp = listPtr->head;
        if(temp->priority > nodePtr->priority)
             return addFirst(nodePtr,listPtr,data,priority,temp); 
        
        while(temp->next!=NULL)
                temp= temp->next;        
        if(temp->priority < nodePtr->priority)
             return addInLast(nodePtr,listPtr,data,priority,temp);
        return addInMiddle(nodePtr,listPtr,data,priority,temp,temp2);
};

int dequeue(list* listPtr){
        node *temp=calloc(sizeof(node),1);
        if(listPtr->length == 0)
                return 0;
        temp = listPtr->head->next;
        listPtr->head = temp;
        listPtr->length -=1;
                return 1;
};
