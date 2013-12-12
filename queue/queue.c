#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
void *getElement(queue *queue1){
	return queue1->elements+(queue1->rear)*(queue1->typeSize);
};
bool isfull(queue *queue1){
	return (queue1->Max==queue1->rear+1);
}
queue* create(int typeSize,int Max){
	queue *queue1=calloc(sizeof(queue),1);
	queue1->elements=calloc(typeSize,Max);
	queue1->Max=Max;
	queue1->front=0;
	queue1->rear=-1;
	queue1->typeSize=typeSize;
	return queue1;
};
bool enqueue(queue *queue1,void *item){
	int address;
	if(isfull(queue1)) return false;
	queue1->rear++;	
	memmove(getElement(queue1),item,queue1->typeSize);
	return true;
};
void* dequeue(queue *queue1){
	int i;
	void *delatedElement=calloc(1,queue1->typeSize);
	memmove(delatedElement,queue1->elements,queue1->typeSize);
	for(i=0;i<queue1->Max;i++){
		memmove(queue1->elements+queue1->typeSize*i,queue1->elements+queue1->typeSize*(i+1),queue1->typeSize);
	};
	queue1->rear--;
	return delatedElement;
};
	
