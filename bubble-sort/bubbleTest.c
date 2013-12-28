#include "testUtils.h"
#include "bubble.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt(void *first,void *second){
	if(*(int *)first >*(int *)second) return -1;
	if(*(int *)first <*(int *)second) return 1;
};

int compareInt(void *first,void *second){
	if(*(double *)first >*(double *)second) return -1;
	if(*(double *)first <*(double *)second) return 1;
};
void test_bubble_sort_should_sort_int_array_elements(){

	int elements[5] = {4,5,3,1,2};
	bubbleSort(elements,5,sizeof(int),compareInt);
	ASSERT(elements[0] = 1);
	ASSERT(elements[4] = 5);
	ASSERT(elements[3] = 4);
};
