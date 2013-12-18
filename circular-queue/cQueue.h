#include <stdbool.h>
typedef char string[100];
typedef struct{
	void * elements;
	int typeSize;
	int Max;
	int rear;
	int front;
}cQueue;
cQueue *create(int typeSize, int Max);
bool enqueue(cQueue *cQueuePtr,void *item);
void *decQueue(cQueue *cQueuePtr);