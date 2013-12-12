#include <stdbool.h>
typedef char string[100];
typedef struct{
	void * elements;
	int typeSize;
	int Max;
	int rear;
	int front;
}queue;
queue *create(int typeSize, int Max);
bool enqueue(queue *queue1,void *item);
bool isfull(queue *queue1);
bool isEmpty(queue *queue1);
void* dequeue(queue *queue1);