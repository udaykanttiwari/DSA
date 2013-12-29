#include "testUtils.h"
#include "mergeSort.h"

typedef  char string[20];
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt (void* first, void* second){
        return *(int*)first < *(int*)second;
}

int compareFloat(void* first, void* second){
        return (*(float*)first < *(float*)second);
}

int compareDouble(void* first, void* second){
        return (*(double*)first < *(double*)second);
}

int compareChar(void* first, void* second){
        return (*(char*)first < *(char*)second);
}

int compareString(void* first, void* second){
        return (0 > strcmp((char*)first, (char*)second));
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
	ASSERT(elements[0] == 1.0);
	ASSERT(elements[3] == 5.0);
}

void test_merge_char_sorted_array_element(){
	char elements[4];
	char left[2] ={'a','b'};
	char right[2] = {'c','d'}; 
	merge(left,right,elements,2,2,compareChar,sizeof(char));
	ASSERT(elements[0] == 'a');
	ASSERT(elements[3] == 'd');
};

void test_merge_string_sorted_array_element(){
	string elements[4];
	string left[2] ={"ab","bc"};
	string right[2] = {"cd","de"}; 
	merge(left,right,elements,2,2,compareString,sizeof(string));
	ASSERT(strcmp(elements[0],"ab") == 0);
	ASSERT(strcmp(elements[3],"de") == 0);
};

void test_merge_sort_shuld_sort_int_array(){
	int elements[4] = {4,2,1,3};
	mergeSort(elements,4,sizeof(int),compareInt);
	ASSERT(elements[0] == 1);
	ASSERT(elements[3] == 4);	
};

void test_merge_sort_shuld_sort_double_element(){
	double elements[4] = {2.0,4.0,1.0,5.0};
	mergeSort(elements,4,sizeof(double),compareDouble);
	ASSERT(elements[0] == 1.0);
	ASSERT(elements[3] == 5.0);
}
