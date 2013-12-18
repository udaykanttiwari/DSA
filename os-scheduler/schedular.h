#include "./include/priorityQueue.h"

typedef struct{
        char processName[20];
        int Time;
        int lifeCycle;
}process;
int insertProcess(list *start,int priority ,void * data);
int excuteProcess(list* start);