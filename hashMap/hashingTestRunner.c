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

	testStarted("test_createHashMap_shuld_create_hash_map");
	setup();
		test_createHashMap_shuld_create_hash_map();
	tearDown();
	testEnded();
	testStarted("test_put_element_to_bucket");
	setup();
		test_put_element_to_bucket();
	tearDown();
	testEnded();
	testStarted("test_put_element_to_bucket_and_get_element");
	setup();
		test_put_element_to_bucket_and_get_element();
	tearDown();
	testEnded();
	testStarted("test_put_element_to_bucket_and_get_element_udaykant");
	setup();
		test_put_element_to_bucket_and_get_element_udaykant();
	tearDown();
	testEnded();
	testStarted("test_put_element_to_bucket_and_it_should_give_null");
	setup();
		test_put_element_to_bucket_and_it_should_give_null();
	tearDown();
	testEnded();
	testStarted("test_put_element_to_bucket_remove_data_from_bucket");
	setup();
		test_put_element_to_bucket_remove_data_from_bucket();
	tearDown();
	testEnded();
	testStarted("test_put_element_into_bucket_and_get_all_keys");
	setup();
		test_put_element_into_bucket_and_get_all_keys();
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
