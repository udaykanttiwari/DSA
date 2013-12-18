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
	testStarted("test_3_push_the_item_into_stack");
	setup();
		test_3_push_the_item_into_stack();
	tearDown();
	testEnded();
	testStarted("test_4_push_the_item_into_stack");
	setup();
		test_4_push_the_item_into_stack();
	tearDown();
	testEnded();
	testStarted("test_5_push_the_item_into_stack");
	setup();
		test_5_push_the_item_into_stack();
	tearDown();
	testEnded();
	testStarted("test_6_create_should_create_a_stack_doulbe_of_5_elements");
	setup();
		test_6_create_should_create_a_stack_doulbe_of_5_elements();
	tearDown();
	testEnded();
	testStarted("test_7_push_the_double_type_item_into_stack");
	setup();
		test_7_push_the_double_type_item_into_stack();
	tearDown();
	testEnded();
	testStarted("test_8_push_the_double_type_item_into_stack");
	setup();
		test_8_push_the_double_type_item_into_stack();
	tearDown();
	testEnded();
	testStarted("test_9_push_character_type_value_into_stack");
	setup();
		test_9_push_character_type_value_into_stack();
	tearDown();
	testEnded();
	testStarted("test_10_pop_integer_type_element_from_stack");
	setup();
		test_10_pop_integer_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_11_pop_double_type_element_from_stack");
	setup();
		test_11_pop_double_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_12_pop_char_type_element_from_stack");
	setup();
		test_12_pop_char_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_13_pop_string_type_element_from_stack");
	setup();
		test_13_pop_string_type_element_from_stack();
	tearDown();
	testEnded();
	testStarted("test_14_push_string_type_element_into_stack");
	setup();
		test_14_push_string_type_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_15_resize_should_allocate_double_memory_when_stack_is_ful");
	setup();
		test_15_resize_should_allocate_double_memory_when_stack_is_ful();
	tearDown();
	testEnded();
	testStarted("test_16_push_the_item_into_stack");
	setup();
		test_16_push_the_item_into_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
