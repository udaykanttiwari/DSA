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

	testStarted("test_create_top");
	setup();
		test_create_top();
	tearDown();
	testEnded();
	testStarted("test_push_doubleeger_element_into_stack");
	setup();
		test_push_doubleeger_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_push_two_integer_element_into_stack");
	setup();
		test_push_two_integer_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_push_two_double_element_into_stack");
	setup();
		test_push_two_double_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_push_two_string_element_into_stack");
	setup();
		test_push_two_string_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_element_from_stack");
	setup();
		test_pop_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_double_element_from_stack");
	setup();
		test_pop_double_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_string_element_into_stack");
	setup();
		test_pop_string_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_should_check_if_stack_is_empty");
	setup();
		test_pop_should_check_if_stack_is_empty();
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
