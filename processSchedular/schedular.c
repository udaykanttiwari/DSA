#include "schedular.h"
	
int insertProcess(list *start ,int priority ,void *data){
	process *processPtr;int Time;
	enqueue(start,priority,data);
	return 1;
};
