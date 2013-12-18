#include "testUtils.h"
#include "bracketMatch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void test_1_bracket_match_should_match_bracketes_from_paragraph(){
	char paragraph[100]="(hello{ how are [you)]})";
	int result=bracketMatch(paragraph);
	ASSERT(1==result);	
};
void test_2_bracket_match_should_not_match_bracketes_from_paragraph(){
	char paragraph[100]="(hello{ how are [you)]}";
	int result=bracketMatch(paragraph);
	ASSERT(0 == result);	
};

void test_3_bracket_match_should_match_bracketes_from_paragraph(){
	char paragraph[100]="{hello}";
	int result=bracketMatch(paragraph);
	ASSERT(1 == result);	
};

void test_4_bracket_match_should_not_match_bracketes_from_paragraph(){
	char paragraph[100]="({hello})";
	int result=bracketMatch(paragraph);
	ASSERT(1== result);	
};
