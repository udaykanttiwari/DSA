#include "bubble.h"
#include <memory.h>
#include <stdlib.h>
void bubbleSort(void *element,int numberOfElements,int typeSize,compareFunc *compare){
	int i,j,count = numberOfElements,compareResult;
	void *temp = (void *)calloc(1,typeSize);
	for(i = 1;i <= numberOfElements-1;i++){
		
		for(j=0;j<count-1;j++){
			compareResult= compare((element+j*typeSize),(element+(j+1)*typeSize));			
			if(compareResult == -1){
				memcpy(temp,(element+j*typeSize),typeSize);
				memcpy((element+j*typeSize),(element+(j+1)*typeSize),typeSize);
				memcpy((element+(j+1)*typeSize),temp,typeSize);					
			};

		};
		count--;
	};
};
