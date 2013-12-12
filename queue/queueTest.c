#include "testUtils.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
queue *queue1;
void tearDown(){
	free(queue1->elements);
	free(queue1);
};
int areEqual(queue expected,queue actual){
	int  result = actual.rear == expected.rear && actual.front == expected.front
	&&actual.Max == expected.Max && actual.typeSize == expected.typeSize;
	if(!result)
		return result;
	return 0==memcmp(expected.elements,actual.elements,actual.Max*actual.typeSize);
};
void test_1_create_should_give_max_size_5(){
	queue1=create(sizeof(int),5);
	ASSERT(5==queue1->Max);
};
void test_2_create_should_create_queue(){
	int elements[5]={0,0,0,0,0};
	queue expected={elements,4,5,-1,0};
	queue1=create(sizeof(int),5);
	ASSERT(areEqual(expected, *queue1));
}
void test_3_insert_value_in_enqueue(){
	int _5=5;
	void *ptr=&_5;
	queue1=create(sizeof(int),5);
	ASSERT(true==enqueue(queue1,ptr));
};
void test_4_insert_integer_value_in_enqueue(){
	int _5=5;
	void *ptr=&_5;
	int elements[5]={5,0,0,0,0};
	queue expected={elements,4,5,0,0};
	queue1=create(sizeof(int),5);
	enqueue(queue1,ptr);
	ASSERT(areEqual(expected,*queue1));
};
void test_5_insert_double_value_in_enqueue(){
	double _5=5.0;
	void *ptr=&_5;
	double elements[5]={5.0,0.0,0.0,0.0,0.0};
	queue expected={elements,sizeof(double),5,0,0};
	queue1=create(sizeof(double),5);
	enqueue(queue1,ptr);
	ASSERT(areEqual(expected,*queue1));
};
void test_6_insert_char_value_in_enqueue(){
	char _a='a';
	void *ptr=&_a;
	char elements[5]={'a',0,0,0,0};
	queue expected={elements,sizeof(char),5,0,0};
	queue1=create(sizeof(char),5);
	enqueue(queue1,ptr);
	ASSERT(areEqual(expected,*queue1));
};
void test_7_should_not_insert_char_value_in_enqueue(){
	char _a='a';int result;
	void *ptr=&_a;
	char elements[5]={'a',0,0,0,0};
	queue1=create(sizeof(char),5);
	enqueue(queue1,ptr);
	enqueue(queue1,ptr);
	enqueue(queue1,ptr);
	enqueue(queue1,ptr);
	enqueue(queue1,ptr);
	result = enqueue(queue1,ptr);
	ASSERT(false==result);
};
void test_8_insert_string_type_element_into_queue_and_return_true(){
	string item="udaykant";
	void *ptr=&item;	
	queue1=create(sizeof(string),5);
	ASSERT(true == enqueue(queue1,ptr));
};
void test_9_insert_string_value_in_enqueue(){
	string item="udaykant";
	void *ptr=&item;	
	string elements[5]={"udaykant",0,0,0,0};
	queue expected={elements,sizeof(string),5,0,0};
	queue1=create(sizeof(string),5);
	enqueue(queue1,ptr);
	ASSERT(areEqual(expected,*queue1));
};
void test_10_dequeue_should_delete_element_from_queue(){
	int _5=5;
	void *result;
	void *ptr=&_5;
	int elements[5]={0,0,0,0,0};
	queue expected={elements,4,5,0,0};
	queue1=create(sizeof(int),5);
	enqueue(queue1,ptr);
	result=dequeue(queue1);
	ASSERT(*(int*)result==5);
};
void test_11_dequeue_should_delete_double_type_of_element_from_queue(){
	double _5=5.0, _6=6.0;
	void *result;
	void *ptr=&_5;
	queue1=create(sizeof(double),5);
	enqueue(queue1,ptr);
	enqueue(queue1,ptr);
	result=dequeue(queue1);
	ASSERT(*(double*)result==5.00000);
};
void test_12_dequeue_should_delete_char_type_of_element_from_queue(){
	char _a='a', _b='b';
	void *result;
	void *ptra=&_a;
	void *ptrb=&_b;
	queue1=create(sizeof(char),5);
	enqueue(queue1,ptra);
	enqueue(queue1,ptrb);
	result=dequeue(queue1);
	ASSERT(*(char*)result=='a');
};
void test_13_dequeue_should_delete_string_type_of_element_from_queue(){
	string item="udaykant";
	void *ptr=&item;void *result;	
	string elements[5]={"udaykant",0,0,0,0};
	queue expected={elements,sizeof(string),5,0,0};
	queue1=create(sizeof(string),5);
	enqueue(queue1,ptr);
	result=dequeue(queue1);
	ASSERT(0==strcmp("udaykant",*(string*)result));
};