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

	testStarted("test_bsearch_should_find_value_from_elements");
	setup();
		test_bsearch_should_find_value_from_elements();
	tearDown();
	testEnded();
	testStarted("test_2_bsearch_should_not_find_value_from_elements");
	setup();
		test_2_bsearch_should_not_find_value_from_elements();
	tearDown();
	testEnded();
	testStarted("test_3_bsearch_should__find_doulbe_value_from_elements");
	setup();
		test_3_bsearch_should__find_doulbe_value_from_elements();
	tearDown();
	testEnded();
	testStarted("test_4_bsearch_should_not_find_doulbe_value_from_elements");
	setup();
		test_4_bsearch_should_not_find_doulbe_value_from_elements();
	tearDown();
	testEnded();
	testStarted("test_5_bsearch_should_not_find_char_value_from_elements");
	setup();
		test_5_bsearch_should_not_find_char_value_from_elements();
	tearDown();
	testEnded();
	testStarted("test_6_bsearch_should_find_string_value_from_elements");
	setup();
		test_6_bsearch_should_find_string_value_from_elements();
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
