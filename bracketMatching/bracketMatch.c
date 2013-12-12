#include "bracketMatch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int bracketMatch(char paragraph[]){
	int i;
	int top=-1,count=0;
	char *ptr=(char*)calloc(1,10);
	for(i=0;i<strlen(paragraph);i++){
		if(paragraph[i]=='('||paragraph[i]=='['||paragraph[i]=='{'){
			top++;	
			*(ptr+top)=paragraph[i];
			printf("%c",*(ptr+top));
				if(paragraph[i]==')'||paragraph[i]==']'||paragraph[i]=='}'){
				printf("*(ptr+top)=%c",*(ptr+top));
				if( (*(ptr+top)=='(' && paragraph[i]==')')||(*(ptr+top)=='[' && paragraph[i]==']')||
				(*(ptr+top)=='{' && paragraph[i]=='}')){
					printf("\nparagraph[i]=%c",paragraph[i]);
				--ptr;
			};
			if(top==-1)
				printf("coming top ");
				return 0;
		};
			

		};
	};
	return 1;
};
