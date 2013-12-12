#include "stack.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

stack *create(int typeSize,int Max){
	stack *stackInstance=calloc(sizeof(stack),1);
	stackInstance->elements=calloc(typeSize,Max);
	printf("size is=%d",sizeof(stackInstance->elements));
	stackInstance->Max=Max;
	stackInstance->top=-1;
	stackInstance->typeSize=typeSize;
	return stackInstance;
};
int isEmpty(stack *stackInstance){
	return stackInstance->top==-1;
};
int isFull(stack *stackInstance){
	return stackInstance->top==stackInstance->Max;
}
void push(stack *stackInstance,void* item){
	int address,i;
	stackInstance->top++;
	address=(stackInstance->top)*(stackInstance->typeSize);
	memcpy(stackInstance->elements+address,item,stackInstance->typeSize);
};
void  *pop(stack *stackInstance){
	int address;void *popElement;
	if(isEmpty(stackInstance)) return false;
	popElement=calloc(stackInstance->typeSize,1);
	address=(stackInstance->top)*(stackInstance->typeSize);
	popElement=stackInstance->elements+address;
	stackInstance->top--;
	return popElement;
};
void dispose(stack *stackInstance){
	free(stackInstance->elements);
	free(stackInstance);
};
