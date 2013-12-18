#include "testUtils.h"
#include "cQueue.h"
#include <stdlib.h>
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
cQueue *InstanceQueue;
void tearDown(){
	dispose(InstanceQueue);
};
int areEqual(cQueue expected,cQueue actual){
	int  result = actual.rear == expected.rear && actual.front == expected.front
	&&actual.Max == expected.Max && actual.typeSize == expected.typeSize;
	if(!result)
		return result;
	return 0==memcmp(expected.elements,actual.elements,actual.Max*actual.typeSize);
};
void test_1_create_should_give_max_size_5(){
	InstanceQueue=create(sizeof(int),5);
	ASSERT(5==InstanceQueue->Max);
};
void test_2_create_should_create_cQueue(){
	int elements[5]={0,0,0,0,0};
	cQueue expected={elements,4,5,-1,-1};
	InstanceQueue=create(sizeof(int),5);
	ASSERT(areEqual(expected, *InstanceQueue));
};
void test_3_insert_value_in_enqueue(){
	int _5=5;
	void *ptr=&_5;
	InstanceQueue = create(sizeof(int),5);
	ASSERT(true==enqueue(InstanceQueue,ptr));
};
void test_4_insert_integer_value_in_enqueue(){
	int _5=5;
	void *ptr=&_5;
	int elements[5]={5,0,0,0,0};
	cQueue expected={elements,4,5,0,-1};
	InstanceQueue=create(sizeof(int),5);
	enqueue(InstanceQueue,ptr);
	ASSERT(areEqual(expected,*InstanceQueue));
};
void test_5_insert_double_value_in_enqueue(){
	double _5=5.0;
	void *ptr=&_5;
	double elements[5]={5.0,0.0,0.0,0.0,0.0};
	cQueue expected={elements,sizeof(double),5,0,-1};
	InstanceQueue=create(sizeof(double),5);
	enqueue(InstanceQueue,ptr);
	ASSERT(areEqual(expected,*InstanceQueue));
};
void test_6_insert_char_value_in_enqueue(){
	char _a='a';
	void *ptr=&_a;
	char elements[5]={'a',0,0,0,0};
	cQueue expected={elements,sizeof(char),5,0,-1};
	InstanceQueue=create(sizeof(char),5);
	enqueue(InstanceQueue,ptr);
	ASSERT(areEqual(expected,*InstanceQueue));
};
void test_7_insert_string_type_element_into_queue_and_return_true(){
	string item="udaykant";
	void *ptr=&item;	
	InstanceQueue=create(sizeof(string),5);
	ASSERT(true == enqueue(InstanceQueue,ptr));
};
void test_8_insert_string_value_in_enqueue(){
	string item="udaykant";
	void *ptr=&item;	
	string elements[5]={"udaykant",0,0,0,0};
	cQueue expected={elements,sizeof(string),5,0,-1};
	InstanceQueue=create(sizeof(string),5);
	enqueue(InstanceQueue,ptr);
	ASSERT(areEqual(expected,*InstanceQueue));
};
void test_9_dequeue_should_dequeued_element_from_queue(){
	int _5=5;
	void *result;
	void *ptr=&_5;
	InstanceQueue=create(sizeof(int),5);
	enqueue(InstanceQueue,ptr);
	result=decQueue(InstanceQueue);
	ASSERT(*(int*)result==5);
};
void test_10_dequeue_should_dequeued_element_from_queue(){
	int _5=5;
	void *result;
	void *ptr=&_5;
	InstanceQueue=create(sizeof(int),5);
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(false == enqueue(InstanceQueue,ptr));
	decQueue(InstanceQueue);	
	decQueue(InstanceQueue);	
	ASSERT(true == enqueue(InstanceQueue,ptr));
};
void test_11_insert_string_type_element_into_queue_and_return_true(){
	string item="udaykant";
	void *ptr=&item;
	string elements[5]={"udaykant","udaykant","udaykant","udaykant","udaykant"};	
	cQueue expected={elements,sizeof(string),5,4,-1};
	InstanceQueue=create(sizeof(string),5);
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(false == enqueue(InstanceQueue,ptr));
	ASSERT(areEqual(expected,*InstanceQueue));
};
void test_12_insert_double_type_element_into_queue_and_return_true(){
	double item=5.0;
	void *ptr=&item;
	double elements[5]={5.0,5.0,5.0,5.0,5.0};	
	cQueue expected={elements,sizeof(double),5,4,-1};
	InstanceQueue=create(sizeof(double),5);
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(true == enqueue(InstanceQueue,ptr));
	ASSERT(false == enqueue(InstanceQueue,ptr));
	ASSERT(areEqual(expected,*InstanceQueue));
};



