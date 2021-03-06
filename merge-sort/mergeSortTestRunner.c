#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_merge_integer_sorted_array_element");
	setup();
		test_merge_integer_sorted_array_element();
	tearDown();
	testEnded();
	testStarted("test_merge_double_sorted_array_element");
	setup();
		test_merge_double_sorted_array_element();
	tearDown();
	testEnded();
	testStarted("test_merge_char_sorted_array_element");
	setup();
		test_merge_char_sorted_array_element();
	tearDown();
	testEnded();
	testStarted("test_merge_string_sorted_array_element");
	setup();
		test_merge_string_sorted_array_element();
	tearDown();
	testEnded();
	testStarted("test_merge_sort_shuld_sort_int_array");
	setup();
		test_merge_sort_shuld_sort_int_array();
	tearDown();
	testEnded();
	testStarted("test_merge_sort_shuld_sort_double_element");
	setup();
		test_merge_sort_shuld_sort_double_element();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
