#include "bSearch.h"
#include <stdio.h>
void* bSearch (void* key,void* base, int num, int  size,compare *compare){
	int first=0;int last=num-1,result;
	int midPoint;
	while(first<=last){
		midPoint = (first+last)/2;
		result = compare(key,base+midPoint*size);
		if(result==0)
			return base+midPoint*size;
		if(result==-1)
			last=midPoint-1;
		if(result==1)
			first=midPoint+1;
	};
	return NULL;	
};
