#include "cQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
void *getElement(cQueue *cQueuePtr){
	return cQueuePtr->elements+(cQueuePtr->rear)*(cQueuePtr->typeSize);
};
bool isfull(cQueue *cQueuePtr){
	int front = cQueuePtr->front;
	int rear = cQueuePtr->rear;
	int length=cQueuePtr->Max;

	return (front-rear==1||(front==-1 && rear == length-1));
}
cQueue* create(int typeSize,int Max){
	cQueue *instanceQueue=calloc(sizeof(cQueue),1);
	instanceQueue->elements=calloc(typeSize,Max);
	instanceQueue->Max=Max;
	instanceQueue->front=-1;
	instanceQueue->rear=-1;
	instanceQueue->typeSize=typeSize;
	return instanceQueue;
};
bool enqueue(cQueue *cQueuePtr,void *item){
	void *address;
	if(isfull(cQueuePtr)==1) return false;
	cQueuePtr->rear++;
	if(cQueuePtr->rear>=cQueuePtr->Max && cQueuePtr->front==0)return false;	
	if(cQueuePtr->rear>=cQueuePtr->Max && cQueuePtr->front>0)
		cQueuePtr->rear=0;
	address=cQueuePtr->elements+(cQueuePtr->typeSize)*(cQueuePtr->rear);
	 memcpy(address,item,cQueuePtr->typeSize);
        return true; 
};
int isEmpty(cQueue *cQueuePtr){
	return cQueuePtr->front==-1 && cQueuePtr->rear==-1;
}
void *decQueue(cQueue *cQueuePtr){
	void *decQueuedElement;
	if(isEmpty(cQueuePtr)) return NULL;
	cQueuePtr->front++;
	return cQueuePtr->elements+(cQueuePtr->front*cQueuePtr->typeSize);
};
void dispose(cQueue *InstanceQueue){ 
	free(InstanceQueue->elements);
	free(InstanceQueue);
};
