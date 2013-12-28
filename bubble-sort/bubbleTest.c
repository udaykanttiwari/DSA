#include "testUtils.h"
#include "bubble.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char* string[20];

int compareInt(void *first,void *second){
	if(*(int *)first >*(int *)second) return -1;
	if(*(int *)first <*(int *)second) return 1;
};

int compareDouble(void *first,void *second){
	if(*(double *)first >*(double *)second) return -1;
	if(*(double *)first <*(double *)second) return 1;
};
int compareFloat(void *first,void *second){
	if(*(float*)first >*(float*)second) return -1;
	if(*(float*)first <*(float*)second) return 1;
};

int compareChar(void *first,void *second){
	if(*(char*)first >*(char*)second) return -1;
	if(*(char*)first <*(char*)second) return 1;
};

int compareString(void *first,void *second){
	return strcmp(*(string *)first,*(string *)second);
};


void test_bubble_sort_should_sort_int_array_elements(){

	int elements[5] = {4,5,3,1,2};
	bubbleSort(elements,5,sizeof(int),compareInt);
	ASSERT(elements[0] == 1);
	ASSERT(elements[4] == 5);
	ASSERT(elements[3] == 4);
};


void test_bubble_sort_should_sort_Double_array_elements(){

	double elements[5] = {4.0,5.0,3.0,1.0,2.0};
	bubbleSort(elements,5,sizeof(double),compareDouble);
	ASSERT(elements[0] == 1.0);
	ASSERT(elements[4] == 5.0);
	ASSERT(elements[3] == 4.0);
};


void test_bubble_sort_should_sort_float_array_elements(){

	float elements[5] = {4.f,5.f,3.f,1.f,2.f};
	bubbleSort(elements,5,sizeof(float),compareFloat);
	ASSERT(elements[0] == 1.f);
	ASSERT(elements[4] == 5.f);
	ASSERT(elements[3] == 4.f);
};

void test_bubble_sort_should_sort_char_array_elements(){

	char elements[5] = {'a','f','d','a','b'};
	bubbleSort(elements,5,sizeof(char),compareChar);
	ASSERT(elements[0] == 'a');
	ASSERT(elements[4] == 'f');
	ASSERT(elements[3] == 'd');
};


void test_bubble_sort_should_sort_string_array_elements(){

	string elements[3] = {"def","abc","bac"};
	bubbleSort(elements,3,sizeof(string),compareString);
	ASSERT(strcmp(elements[0],"abc"));
	ASSERT(strcmp(elements[1],"bac"));
};