#include "testUtils.h"
#include "arrayList.h"
#include <stdlib.h>
const int SUCCESS = 1;
const int FAILURE = 0;
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;
ArrayList *tanbirka;
//-----------------------------------------------------------------------------------------------------------
void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
};

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0 , &prateek);
	Intern *actual = (Intern*)get(internsPtr,0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&ji == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&ji == get(listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&tanbirka == get(internsPtr, 1));
	ASSERT(&ji == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
};

void test_insert_element_and_remove_element(){
	int result = insert(internsPtr, 0 , &prateek);
	remove(internsPtr,0);
	ASSERT(result == SUCCESS);
};

void test_insert_element_and_not_remove_any_element(){
	int result;
	insert(internsPtr, 0 , &prateek);
	insert(internsPtr, 0 , &ji);
	result = remove(internsPtr,4);
	ASSERT(result == FAILURE);
};

void test_insert_element_and__remove_element(){
	int result;
	insert(internsPtr, 0 , &prateek);
	insert(internsPtr, 1 , &ji);
	result = remove(internsPtr,1);
	ASSERT(result == SUCCESS);
	ASSERT(&prateek == get(internsPtr,0));
};
void test_insert_element_get_element_and_remove_element(){
	int result;
	insert(internsPtr, 0 , &prateek);
	insert(internsPtr, 1 , &ji);
	ASSERT(&ji == get(internsPtr,1));
	result = remove(internsPtr,0);
	ASSERT(&ji == get(internsPtr,0));
};
int compareInt(void* first,void* second){
    Intern firstIntern = *(Intern*)first;
    Intern secondIntern = *(Intern*)second;
    return firstIntern.id == secondIntern.id;
}
void test_search_string_element_by_binary_search(){
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 2, &tanbirka);
	ASSERT(0 == search(internsPtr, &prateek,compareInt));
};
