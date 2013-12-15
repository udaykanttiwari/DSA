#include "testUtils.h"
#include "stackUsingLinkList.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
list *top;
void test_create_top(){
	top = create();
	ASSERT(top->head==NULL);
	ASSERT(top->length==0);
};
void test_push_doubleeger_element_into_stack(){
	int data=100,result;
	top = create();
	result=push(top,&data);
	ASSERT(result==1);
};
void test_push_two_integer_element_into_stack(){
	int data=100,result;
	int data1 = 200;
	top = create();
	result=push(top,&data);
	result=push(top,&data1);
	ASSERT(result==1);
	ASSERT(*(int *)top->head->data==200);
	ASSERT(*(int *)top->head->next->data==100);
};

void test_push_two_double_element_into_stack(){
	double data=100.0,result;
	double data1 = 200.0;
	top = create();
	result=push(top,&data);
	result=push(top,&data1);
	ASSERT(result==1);
	ASSERT(*(double *)top->head->data==200.0);
	ASSERT(*(double *)top->head->next->data==100.0);
};
void test_push_two_string_element_into_stack(){
 	int result;
 	string name1="ansu";
	string name2 = "manish";
	top = create();
	result=push(top,name1);
	result=push(top,name2);
	ASSERT(result==1);
	ASSERT(0==strcmp(top->head->data,"manish"));
	ASSERT(0==strcmp(top->head->next->data,"ansu"));
};
void test_pop_element_from_stack(){
	int data=100,result;
	int data1 = 200;
	top = create();
	result=push(top,&data);
	result=push(top,&data1);
	result = pop(top);
	ASSERT(result==1);
};
void test_pop_double_element_from_stack(){
	double data=100.0,result;
	double data1 = 200.0;
	top = create();
	result=push(top,&data);
	result=push(top,&data1);
	result = pop(top);
	ASSERT(result==1);
	ASSERT(*(double*)top->head->data==100.0);
};
void test_pop_string_element_into_stack(){
 	int result;
 	string name1="ansu";
	string name2 = "manish";
	top = create();
	result=push(top,name1);
	result=push(top,name2);
	result = pop(top);
	ASSERT(result==1);
	ASSERT(0==strcmp(top->head->data,"ansu"));
};
void test_pop_should_check_if_stack_is_empty(){
	int result;
	top = create();
	result = pop(top);
	ASSERT(result==0);
}
