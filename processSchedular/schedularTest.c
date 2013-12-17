#include "testUtils.h"
#include "schedular.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
list *start;
process *processPtr;
void test_create_should_create_start(){
	start= create();
	ASSERT(start->head == NULL);
	ASSERT(start->length == 0);	
};
void test_insert_process_in_insert_process(){
	int result;
	process Process = {20,"browser"};		
	start= create();
	result = insertProcess(start,3,&Process);
	ASSERT(result == 1);
	processPtr = start->head->data;
	ASSERT(processPtr->Time == 20);
	ASSERT(strcmp(processPtr->processName,"browser")==0);

};
void test_excuteProcess_should_excute_the_process(){
	int result;
	process process1 = {20,"browser"};
	process process2 = {10,"browser2"};	
	process process3 = {100,"browser3"};				

	start= create(); 
	result = insertProcess(start,3,&process1);
	result = insertProcess(start,2,&process2);
	result = insertProcess(start,1,&process3);
	result = executeProcess(start);
	ASSERT(result == 1);
	processPtr = start->head->data;
	ASSERT(processPtr->Time == 20);
	ASSERT(strcmp(processPtr->processName,"browser")==0);

};
