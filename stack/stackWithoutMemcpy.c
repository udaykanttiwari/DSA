#include "stackWithoutMemcpy.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

stack *create(int typeSize,int length){
	stack *stackInstance=calloc(sizeof(stack),1);
	stackInstance->elements=calloc(sizeof(void *),length);
	stackInstance->length=length;
	stackInstance->top=-1;
	stackInstance->typeSize=typeSize;
	return stackInstance;
};
stack* resize(stack *stackInstance){
	int length= stackInstance->length;
	int size = stackInstance->typeSize;
	stackInstance->elements = realloc(stackInstance->elements,(length*2)*size);
	stackInstance->length = length*2;
	return stackInstance;
};

int isEmpty(stack *stackInstance){
	return stackInstance->top==-1;
};
int isFull(stack *stackInstance){
	int top = (stackInstance->top);
	return top == stackInstance->length-1;
}
int push(stack *stackInstance,void* item){
	int address,i,result;
	result = isFull(stackInstance);
	if(result==true){
		resize(stackInstance);
	};
	stackInstance->top++;
	address=(stackInstance->top)*(stackInstance->typeSize);
	*(stackInstance->elements+(++stackInstance->top)) = item;
	return 1;
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
