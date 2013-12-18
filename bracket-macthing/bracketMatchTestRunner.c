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

	testStarted("test_1_bracket_match_should_match_bracketes_from_paragraph");
	setup();
		test_1_bracket_match_should_match_bracketes_from_paragraph();
	tearDown();
	testEnded();
	testStarted("test_2_bracket_match_should_not_match_bracketes_from_paragraph");
	setup();
		test_2_bracket_match_should_not_match_bracketes_from_paragraph();
	tearDown();
	testEnded();
	testStarted("test_3_bracket_match_should_match_bracketes_from_paragraph");
	setup();
		test_3_bracket_match_should_match_bracketes_from_paragraph();
	tearDown();
	testEnded();
	testStarted("test_4_bracket_match_should_not_match_bracketes_from_paragraph");
	setup();
		test_4_bracket_match_should_not_match_bracketes_from_paragraph();
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
