#include "testUtils.h"
#include "schedular.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
list *start;
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
};
