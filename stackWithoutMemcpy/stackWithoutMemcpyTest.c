#include "testUtils.h"
#include "stackWithoutMemcpy.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
#include <memory.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
stack *stackInstance;
void tearDown(){
 	dispose(stackInstance);
};
int areEqual(stack expected,stack actual){
	int  result = actual.top == expected.top && actual.length == expected.length;
	if(!result)
		return result;
	return 0==memcmp(expected.elements,actual.elements,actual.length*actual.typeSize);
};
void test_1_create_should_give_max_size_5(){
	stackInstance=create(sizeof(void*),5);
	ASSERT(5==stackInstance->length);
};
void test_2_create_should_create_a_stack_integer_of_5_elements(){
	void* elements[5]={0,0,0,0,0};
	stack expected={elements,sizeof(void *),5,-1};
	stackInstance=create(sizeof(void *),5);
	ASSERT(areEqual(expected,*stackInstance));
};

void test_3_pop_integer_type_element_from_stack(){
	int item1=5,item2=4,result;
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(void *),5);
	push(stackInstance,ptr1);
	result = push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT(1==result);
};
void test_4_pop_double_type_element_from_stack(){
	double item1=5.0,item2=4.0;int result;
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(void *),5);
	result = push(stackInstance,ptr1);
	result = push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT(1 == result);
};
void test_5_pop_char_type_element_from_stack(){
	char item1='a',item2='b';int result;
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(void *),5);
	push(stackInstance,ptr1);
	result = push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT(1 == result);
};
void test_6_pop_string_type_element_from_stack(){
	string item1="udaykant",item2="ansu";int result;
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(void *),5);
	push(stackInstance,ptr1);
	result = push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT(result == 1);
};
void test_7_resize_should_allocate_double_memory_when_stack_is_ful(){
	stack *reallocate;
	stackInstance=create(sizeof(void *),5);
	reallocate = resize(stackInstance);
	ASSERT(reallocate->length==10);	
};




