#include "stackUsingLinkList.h"
int push(list *top,void *data){
	int index=1;	
	return insert(top,index, data);
};
int pop(list *top){
	int index=1;
	return Remove(top, index);
};
