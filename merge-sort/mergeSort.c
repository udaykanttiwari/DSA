#include "mergeSort.h"
#include <memory.h>

void merge(void *left,void *right,void *base,int lengthOfleft,int lengthofRight,compare *cmp,int typeSize){
	int i=0,j=0,k=0;
	while(i<lengthOfleft && j<lengthofRight){
		if(cmp(left+i*typeSize,right+j*typeSize)){
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
void mergeSort(void* base, int length, int typeSize, compare cmp){
        int mid = length/2,i,j,lenthOfLeft,lenthOfRight;
        void* left = calloc(mid,typeSize);
        void* right = calloc((length-mid),typeSize);
        if(length < 2) return;
        lenthOfLeft = mid;
        lenthOfRight = length-mid;
        for(i=0;i<mid;i++)
                memcpy(left+i*typeSize,base+i*typeSize,typeSize);
        for(i=mid;i<length;i++)
                memcpy(right+typeSize*(i-mid),base+typeSize*i,typeSize);
        mergeSort(left,lenthOfLeft,typeSize,cmp);
        mergeSort(right,lenthOfRight,typeSize,cmp);
        merge(left,right,base,lenthOfLeft,lenthOfRight,cmp,typeSize);
};