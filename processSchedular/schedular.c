#include "schedular.h"
	
int insertProcess(list *start ,int priority ,void *data){
	process *processPtr;int Time;
	enqueue(start,priority,data);
	return 1;
};

int getMaxTime(list* start){
	int maxTime,count=0;
	node *temp = calloc(1, sizeof(node));
	node *temp1 = calloc(1, sizeof(node)); 
	process *processPtr1,*processPtr2;
	temp = start->head;
	while(temp != NULL){
		temp1 = temp;
		processPtr1 = temp1->data;
		temp =temp->next;
		processPtr2 = temp->data;
		maxTime = processPtr1->Time;
		if(maxTime<processPtr2->Time)
			maxTime = processPtr2->Time;
	};
	printf("maxTime %d ",maxTime);

		return maxTime;
}

int executeProcess(list* start){
	int maxTime = getMaxTime(start);
	return 1;
}
