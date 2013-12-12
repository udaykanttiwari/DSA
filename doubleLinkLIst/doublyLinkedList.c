#include "doublyLinkedList.h"

list *create(){
	list* start = (list*)calloc(sizeof(list),1);
	start->head = NULL;
	start->length = 0;
	return start;
};

node* createNode(void *data){
	node* nodePtr = (node*)calloc(sizeof(node),1);
	nodePtr->data = data;
	return nodePtr;
}

int insert(list* start , int index , void* data){
	node* nodePtr, *temp;
	if(start->head == NULL && index == 1){
		nodePtr = createNode(data);
		nodePtr->next =NULL;
		nodePtr->pre = NULL;
		start->head = nodePtr;
		start->length += 1; 
		return 1;	
	}
	if(index == 1){
		nodePtr = createNode(data);
		nodePtr->next = start->head;
		nodePtr->pre = NULL;
		start->head = nodePtr;
		start->length += 1;
		return 1; 
	}

	if(index == start->length+1){
		nodePtr = createNode(data);
		nodePtr->next=NULL;
		temp = createNode(data);
		temp->next = start->head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = nodePtr;
		nodePtr->pre = temp;
		return 1;
	};

	return 0;
}
