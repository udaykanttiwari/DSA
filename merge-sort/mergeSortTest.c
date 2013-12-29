#include "testUtils.h"
#include "mergeSort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void *first ,void *second){
	if((*(int *)first) <= (*(int *)second)) return 1;
}
void test_merge_integer_sorted_array_element(){
	int elements[4];
	int left[2] ={2,4};
	int right[2] = {1,5}; 
	merge(left,right,elements,2,2,compareInt,4);
	ASSERT(elements[0] == 1);
	ASSERT(elements[3] == 5);
}
