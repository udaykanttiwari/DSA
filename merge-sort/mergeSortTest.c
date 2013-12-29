#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void *first ,void *second){
	if((*(int *)first) <= (*(int *)second)) return 1;
}

int compareDouble(void *first ,void *second){
	if((*(double *)first) <= (*(double *)second)) return 1;
}

int compareChar(void *first ,void *second){
	if((*(char *)first) <= (*(char *)second)) return 1;
}
void test_merge_integer_sorted_array_element(){
	int elements[4];
	int left[2] ={2,4};
	int right[2] = {1,5}; 
	merge(left,right,elements,2,2,compareInt,4);
	ASSERT(elements[0] == 1);
	ASSERT(elements[3] == 5);
}
void test_merge_double_sorted_array_element(){
	double elements[4];
	double left[2] ={2.0,4.0};
	double right[2] = {1.0,5.0}; 
	merge(left,right,elements,2,2,compareDouble,sizeof(double));
	printf("%d",elements[3]);
	ASSERT(elements[0] == 1.0);
	ASSERT(elements[3] == 5.0);
}

void test_merge_char_sorted_array_element(){
	char elements[4];
	char left[2] ={'a','b'};
	char right[2] = {'c','d'}; 
	merge(left,right,elements,2,2,compareChar,sizeof(char));
	printf("%d",elements[3]);
	ASSERT(elements[0] == 'a');
	ASSERT(elements[3] == 'd');
}
