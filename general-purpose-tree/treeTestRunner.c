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

	testStarted("test_1_to_create_tree_");
	setup();
		test_1_to_create_tree_();
	tearDown();
	testEnded();
	testStarted("test_2_create_tree_and_insert_root_with_int_data");
	setup();
		test_2_create_tree_and_insert_root_with_int_data();
	tearDown();
	testEnded();
	testStarted("test_3_create_tree_and_insert_root_with_a_char_data");
	setup();
		test_3_create_tree_and_insert_root_with_a_char_data();
	tearDown();
	testEnded();
	testStarted("test_4_create_tree_and_insert_root_with_double_type_of_data");
	setup();
		test_4_create_tree_and_insert_root_with_double_type_of_data();
	tearDown();
	testEnded();
	testStarted("test_5_insert_should_insert_a_child_to_root_node");
	setup();
		test_5_insert_should_insert_a_child_to_root_node();
	tearDown();
	testEnded();
	testStarted("test_6_insert_should_insert_two_children_to_root_node");
	setup();
		test_6_insert_should_insert_two_children_to_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_should_insert_children_to_any_child");
	setup();
		test_insert_should_insert_children_to_any_child();
	tearDown();
	testEnded();
	testStarted("test_insert_should_not_insert_if_child_parents_is_not_availble");
	setup();
		test_insert_should_not_insert_if_child_parents_is_not_availble();
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
