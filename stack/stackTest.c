#include "testUtils.h"
#include "stack.h"
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
	stackInstance=create(sizeof(int),5);
	ASSERT(5==stackInstance->length);
};
void test_2_create_should_create_a_stack_integer_of_5_elements(){
	int a, elements[5]={0,0,0,0,0};
	stack expected={elements,sizeof(int),5,-1};
	stackInstance=create(sizeof(int),5);
	ASSERT(areEqual(expected,*stackInstance));
};
void test_3_push_the_item_into_stack(){
	int item=5;
	void *ptr=&item;	
	int elements[]={5,0,0,0,0};
	stack expected={elements,sizeof(int),5,0};	
	stackInstance=create(sizeof(int),5);
	push(stackInstance,ptr);
	ASSERT(areEqual(expected,*stackInstance));
};

void test_4_push_the_item_into_stack(){
	int item=3;
	void *ptr=&item;	
	int elements[]={3,0,0,0,0};
	stack expected={elements,sizeof(int),5,0};	
	stackInstance=create(sizeof(int),5);		
	push(stackInstance,ptr);
	ASSERT(areEqual(expected,*stackInstance));
};
void test_5_push_the_item_into_stack(){
	int item1=5,item2=6;
	void *ptr1=&item1;
	void *ptr2=&item2;	
	int elements[]={5,6,0,0,0};
	stack expected={elements,sizeof(int),5,1};	
	stackInstance=create(sizeof(int),5);
	push(stackInstance,ptr1);
	push(stackInstance,ptr2);
	ASSERT(areEqual(expected,*stackInstance));
};
void test_6_create_should_create_a_stack_doulbe_of_5_elements(){
	double elements[5]={0.0,0.0,0.0,0.0,0.0};
	stack expected={elements,sizeof(double),5,-1};
	stackInstance=create(sizeof(double),5);
	ASSERT(areEqual(expected,*stackInstance));
};
void test_7_push_the_double_type_item_into_stack(){
	double item=3.0;
	void *ptr=&item;	
	double elements[]={3.0,0.0,0.0,0.0,0.0};
	stack expected={elements,sizeof(double),5,0};	
	stackInstance=create(sizeof(double),5);		
	push(stackInstance,ptr);
	ASSERT(areEqual(expected,*stackInstance));
};

void test_8_push_the_double_type_item_into_stack(){
	double item1=3.0,item2=5.0;
	void *ptr1=&item1;
	void *ptr2=&item2;	
	double elements[]={3.0,5.0,0.0,0.0,0.0};
	stack expected={elements,sizeof(double),5,1};	
	stackInstance=create(sizeof(double),5);		
	push(stackInstance,ptr1);
	push(stackInstance,ptr2);
	ASSERT(areEqual(expected,*stackInstance));
};
void test_9_push_character_type_value_into_stack(){
	char item='a';
	void *ptr=&item;
	char elements[]={'a',0,0,0,0};
	stack expected={elements,sizeof(char),5,0};
	stackInstance=create(sizeof(char),5);
	push(stackInstance,ptr);
	ASSERT(areEqual(expected,*stackInstance));
};
void test_10_pop_integer_type_element_from_stack(){
	int item1=5,item2=4;
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(int),5);
	push(stackInstance,ptr1);
	push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT(4==*(int *)popAddress);
};
void test_11_pop_double_type_element_from_stack(){
	double item1=5.0,item2=4.0;
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(double),5);
	push(stackInstance,ptr1);
	push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT(4.0==*(double *)popAddress);
};
void test_12_pop_char_type_element_from_stack(){
	char item1='a',item2='b';
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(char),5);
	push(stackInstance,ptr1);
	push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT('b'==*(char *)popAddress);
};
void test_13_pop_string_type_element_from_stack(){
	string item1="udaykant",item2="ansu";
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;	
	stackInstance=create(sizeof(string),5);
	push(stackInstance,ptr1);
	push(stackInstance,ptr2);
	popAddress=pop(stackInstance);
	ASSERT(0==strcmp(*(string *)popAddress,"ansu"));
};
void test_14_push_string_type_element_into_stack(){
	string item1="udaykant",item2="ansu";
	void *popAddress;
	void *ptr1=&item1,*ptr2=&item2;
	string elements[5]={"udaykant","ansu",0,0,0};
	stack expected={elements,sizeof(string),5,1};
	stackInstance=create(sizeof(string),5);
	memmove(expected.elements,elements,5*sizeof(string));
	push(stackInstance,ptr1);
	push(stackInstance,ptr2);
	ASSERT(areEqual(expected,*stackInstance));
};
void test_15_resize_should_allocate_double_memory_when_stack_is_ful(){
	stack *reallocate;
	stackInstance=create(sizeof(int ),5);
	reallocate = resize(stackInstance);
	ASSERT(reallocate->length==10);	
};
void test_16_push_the_item_into_stack(){
	int item=5;	
	int elements[]={5,5,5,5,5,5};
	stack expected={elements,sizeof(int),6,5};	
	stackInstance=create(sizeof(int),3);
	push(stackInstance,&item);
	push(stackInstance,&item);
	push(stackInstance,&item);
	push(stackInstance,&item);
	push(stackInstance,&item);
	push(stackInstance,&item);
	ASSERT(areEqual(expected,*stackInstance));
};



