#include "./include/priorityQueue.h"
#include <string.h>
typedef char string[20];

typedef struct {
	int Time;
	string processName;
}process;
int insertProcess(list *,int ,void *);
int executeProcess(list*);