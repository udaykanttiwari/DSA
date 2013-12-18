#include "schedular.h"
int insertProcess(list *start ,int priority ,void *data){
        process *processPtr;int Time;
        enqueue(start,priority,data);
        return 1;
};

int excuteProcess(list* start){
        int processFinished = 0;
        int index = 0;
        node* temp;
        process* ongoingProcess;
        temp = start->head;
        while(processFinished <= start->length){
                if(temp == NULL){
                        temp = start->head;
                        index = 0;                        
                }
                ongoingProcess = temp->data;
                if(ongoingProcess->Time <= 10){
                        processFinished++;
                        ongoingProcess->lifeCycle +=1;        
                        index++;
                        
                }
                ongoingProcess->Time -= 10;
                ongoingProcess->lifeCycle += 1;
                index++;
                temp = temp->next;
        }
        return 1;
}