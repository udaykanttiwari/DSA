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
	testStarted("test_2_create_should_create_queue");
	setup();
		test_2_create_should_create_queue();
	tearDown();
	testEnded();
	testStarted("test_3_insert_value_in_enqueue");
	setup();
		test_3_insert_value_in_enqueue();
	tearDown();
	testEnded();
	testStarted("test_4_insert_integer_value_in_enqueue");
	setup();
		test_4_insert_integer_value_in_enqueue();
	tearDown();
	testEnded();
	testStarted("test_5_insert_double_value_in_enqueue");
	setup();
		test_5_insert_double_value_in_enqueue();
	tearDown();
	testEnded();
	testStarted("test_6_insert_char_value_in_enqueue");
	setup();
		test_6_insert_char_value_in_enqueue();
	tearDown();
	testEnded();
	testStarted("test_7_should_not_insert_char_value_in_enqueue");
	setup();
		test_7_should_not_insert_char_value_in_enqueue();
	tearDown();
	testEnded();
	testStarted("test_8_insert_string_type_element_into_queue_and_return_true");
	setup();
		test_8_insert_string_type_element_into_queue_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_9_insert_string_value_in_enqueue");
	setup();
		test_9_insert_string_value_in_enqueue();
	tearDown();
	testEnded();
	testStarted("test_10_dequeue_should_delete_element_from_queue");
	setup();
		test_10_dequeue_should_delete_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_11_dequeue_should_delete_double_type_of_element_from_queue");
	setup();
		test_11_dequeue_should_delete_double_type_of_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_12_dequeue_should_delete_char_type_of_element_from_queue");
	setup();
		test_12_dequeue_should_delete_char_type_of_element_from_queue();
	tearDown();
	testEnded();
	testStarted("test_13_dequeue_should_delete_string_type_of_element_from_queue");
	setup();
		test_13_dequeue_should_delete_string_type_of_element_from_queue();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
