#include "testUtils.h"
#include "doublyLinkedList.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
list* start;

void test_create_should_assign_null_to_head_and_0_to_length(){
	start = create();
	ASSERT(start->head == NULL);
	ASSERT(start->length == 0);
 };

void test_insert_should_insert_first_node(){
 	int element = 100, answer;
 	start = create();
 	answer = insert(start,1,&element);
 	ASSERT(answer == 1);
};

void test_insert_should_insert_node_in_the_frist_position(){
 	int element = 100, element2 = 200,answer;
 	start = create();
 	answer = insert(start,1,&element);
 	answer = insert(start,1,&element2);
 	ASSERT(answer == 1);
};
void test_insert_should_insert_node_in_the_last_position(){
 	int element = 100, element2 = 200,answer;
 	start = create();
 	answer = insert(start,1,&element);
 	answer = insert(start,1,&element2);
 	answer = insert(start,3,&element2);
  	ASSERT(answer == 1);
};



