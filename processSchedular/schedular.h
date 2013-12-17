#include "./include/priorityQueue.h"
typedef char string[20];

typedef struct 
{
	int Time;
	string processName;
}process;
int insertProcess(list *,int ,void *);