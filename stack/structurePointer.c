#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
	int i;void *elements;
	elements=calloc(sizeof(char),5);
	for(i=0;i<5;i++){
		printf("%c",*(char *)elements+i*sizeof(char));
	}

}