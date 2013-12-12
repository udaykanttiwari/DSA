#include "testUtils.h"
#include "bSearch.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int compareInt(const void* key,const void* element){
	if(*(int *)key<*(int *)element) return -1;
	if(*(int *)key==*(int *)element) return 0;
	if(*(int *)key>*(int *)element) return 1;
};
int compareDouble(const void* key,const void* element){
	if(*(double *)key<*(double *)element) return -1;
	if(*(double *)key==*(double *)element) return 0;
	if(*(double *)key>*(double *)element) return 1;
};
int compareString(const void* key,const void* element){
		return strcmp(*(string*)key,*(string*)element);
};
int compareChar(const void* key,const void* element){
	if(*(char *)key<*(char *)element) return -1;
	if(*(char *)key==*(char *)element) return 0;
	if(*(char *)key>*(char *)element) return 1;
};
void test_bsearch_should_find_value_from_elements(){
	int key=6;int result;
	int elements[5]={1,2,3,6,8};
	ASSERT(6==*(int *)(bSearch(&key,elements,5,sizeof(int),compareInt)));
}
void test_2_bsearch_should_not_find_value_from_elements(){
	int key=14;int result;
	int elements[5]={1,2,3,6,8};
	ASSERT(NULL==(bSearch(&key,elements,5,sizeof(int),compareInt)));
}
void test_3_bsearch_should__find_doulbe_value_from_elements(){
	double key=2.0;
	double elements[5]={1.0,2.0,3.0,6.0,8.0};
	ASSERT(2.0==*(double*)(bSearch(&key,elements,5,sizeof(double),compareDouble)));
}
void test_4_bsearch_should_not_find_doulbe_value_from_elements(){
	double key=2.5;
	double elements[5]={1.0,2.0,3.0,6.0,8.0};
	ASSERT(NULL==(bSearch(&key,elements,5,sizeof(double),compareDouble)));
}
void test_5_bsearch_should_not_find_char_value_from_elements(){
	char key='a';
	char elements[5]={'b','c','a','d','e'};
	ASSERT('a'==*(char*)(bSearch(&key,elements,5,sizeof(char),compareChar)));
}
void test_6_bsearch_should_find_string_value_from_elements(){
	string key="prateek",result;
	string elements[5]={"ansu","manish","prateek","tikash","vikash"};
	ASSERT(0==strcmp("prateek",*(string*)(bSearch(&key,elements,5,sizeof(string),compareString))));
};


