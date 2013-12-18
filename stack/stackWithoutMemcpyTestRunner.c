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

	testStarted("test_1_create_should_give_max_size_5");
	setup();
		test_1_create_should_give_max_size_5();
	tearDown();
	testEnded();
	testStarted("test_2_create_should_create_a_stack_integer_of_5_elements");
	setup();
		test_2_create_should_create_a_stack_integer_of_5_elements();
	tearDown();
	testEnded();
	testStarted("test_3_pop_integer_type_element_from_stack");
	setup();
		test_3_pop_integer_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_4_pop_double_type_element_from_stack");
	setup();
		test_4_pop_double_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_5_pop_char_type_element_from_stack");
	setup();
		test_5_pop_char_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_6_pop_string_type_element_from_stack");
	setup();
		test_6_pop_string_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_7_resize_should_allocate_double_memory_when_stack_is_ful");
	setup();
		test_7_resize_should_allocate_double_memory_when_stack_is_ful();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
