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

	testStarted("test_isort_should_sortInteger_elements");
	setup();
		test_isort_should_sortInteger_elements();
	tearDown();
	testEnded();
	testStarted("test_isort_should_sortchar_elements");
	setup();
		test_isort_should_sortchar_elements();
	tearDown();
	testEnded();
	testStarted("test_isort_should_sort_string_elements");
	setup();
		test_isort_should_sort_string_elements();
	tearDown();
	testEnded();
	testStarted("test_isort_should_sort_double_elements");
	setup();
		test_isort_should_sort_double_elements();
	tearDown();
	testEnded();
	testStarted("test_isort_should_sort_float_elements");
	setup();
		test_isort_should_sort_float_elements();
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
