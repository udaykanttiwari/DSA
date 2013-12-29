#include "mergeSort.h"
#include <memory.h>
void merge(void *left,void *right,void *base,int lengthOfleft,int lengthofRight,compare *cmp,int typeSize){
	int i=0,j=0,k=0;
	while(i<lengthOfleft && j<lengthofRight){
		if(cmp(left+i*typeSize,right+j*typeSize)==1){
			memcpy(base+k*typeSize,left+i*typeSize,typeSize);
			i++;
		}
		else
			{
			memcpy(base+k*typeSize,right+j*typeSize,typeSize);
			j++;
		};
		k++;
	};
	while(i<lengthOfleft){
		memcpy(base+k*typeSize,left+i*typeSize,typeSize);
		i++;
		k++;
	};
	while(j<lengthOfleft){
		memcpy(base+k*typeSize,right+j*typeSize,typeSize);
		j++;
		k++;
	};
};

