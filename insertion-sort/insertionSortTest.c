#include "testUtils.h"
#include "insertionSort.h"
#include <stdio.h>
#include <string.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
int accountNumber;
int balance;
} Account;

int compareInteger(void *first,void *second){
	return *(int *)first - *(int *)second;
};
int compareFloat(void *first,void *second){
	return *(float *)first - *(float *)second;
};
int compareChar(void *first,void *second){
	return *(char *)first - *(char *)second;
};
int compareDouble(void *first,void *second){
	return *(double *)first - *(double *)second;
};
int compareString(void *first,void *second){
	return strcmp(*(string *)first,*(string *)second);
};
int compareAccountsByAccountNumber(void* first, void* second) {
Account* firstAccount = (Account*)first;
Account* secondAccount = (Account*)second;
return firstAccount->accountNumber - secondAccount->accountNumber;
}

int compareAccountsByBalance(void* first, void* second) {
Account* firstAccount = (Account*)first;
Account* secondAccount = (Account*)second;
return firstAccount->balance - secondAccount->balance;
}
void test_isort_should_sortInteger_elements(){
	int elements[] = {1,4,2,4,6};
	isort(elements,5, sizeof(int), compareInteger);
	ASSERT(elements[0] == 1);
	ASSERT(elements[1] == 2);
	ASSERT(elements[2] == 4);
	ASSERT(elements[3] == 4);
	ASSERT(elements[4] == 6); 
};
void test_isort_should_sortchar_elements(){
	char elements[] = {'a','b','c','e','d'};
	isort(elements,5, sizeof(char), compareChar);
	ASSERT(elements[0] == 'a');
	ASSERT(elements[1] == 'b');
	ASSERT(elements[2] == 'c');
	ASSERT(elements[3] == 'd');
	ASSERT(elements[4] == 'e');	
};
void test_isort_should_sort_string_elements(){
	string elements[] = {"uday","ansu","manish","vikah","v"};
	isort(elements,5, sizeof(string), compareString);
	ASSERT(0==strcmp(elements[0],"ansu"));
	ASSERT(0==strcmp(elements[1],"manish"));
	ASSERT(0==strcmp(elements[2],"uday"));
	ASSERT(0==strcmp(elements[3],"v"));
	ASSERT(0==strcmp(elements[4],"vikah"));
}
void test_isort_should_sort_double_elements(){
	double elements[] = {1.0,4.0,2.0,4.0,6.0};
	isort(elements,5, sizeof(double), compareDouble);
	ASSERT(elements[0] == 1.0);
	ASSERT(elements[1] == 2.0);
	ASSERT(elements[2] == 4.0);
	ASSERT(elements[3] == 4.0);
	ASSERT(elements[4] == 6.0); 
};
void test_isort_should_sort_float_elements(){
	float elements[] = {1.0f,4.0f,2.0f,4.0f,6.0f};
	isort(elements,5, sizeof(float), compareFloat);
	ASSERT(elements[0] == 1.0f);
	ASSERT(elements[1] == 2.0f);
	ASSERT(elements[2] == 4.0f);
	ASSERT(elements[3] == 4.0f);
	ASSERT(elements[4] == 6.0f); 
};

