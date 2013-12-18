#include "bracketMatch.h"
#include <string.h>
void pushBracket(stack *stackPtr,char paragraph[]){
	int i;
	for(i=0;i<strlen(paragraph);i++){
		if(paragraph[i]=='('||paragraph[i]=='['||paragraph[i]=='{'){
			push(stackPtr,&paragraph[i]);
		};
	};

};
int popBracket(stack *stackPtr,char paragraph[]){
	int i;
	for(i=0;i<strlen(paragraph);i++){
		if(paragraph[i]==')'||paragraph[i]==']'||paragraph[i]=='}'){
			if((*(char *)stackPtr->elements+stackPtr->top == '(' && paragraph[i]==')')|| (*(char *)stackPtr->elements+stackPtr->top  && paragraph[i]==']')||
				(*(char *)stackPtr->elements+stackPtr->top  && paragraph[i]=='}')){
				pop(stackPtr);
				if(stackPtr->top == -1)
					return 1;

				};	
			};
		};
	return 0;

};
int bracketMatch(char paragraph[]){
	int i;
	int top,count=0;
	stack *stackPtr=create(sizeof(char),10);
	pushBracket(stackPtr,paragraph);
	return popBracket(stackPtr,paragraph);
};
