#include <stdbool.h>
typedef struct{
	void * elements;
	int typeSize;
	int length;
	int top;
}stack;
typedef char string[100];
stack *create(int typeSize, int length);
void push(stack *stackInstance,void* item);
int pop(stack *stackInstance);
