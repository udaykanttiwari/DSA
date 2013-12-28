#include "hashing.h"

HashMap* createHashMap(HashCodeGenerator hash, compareFptr compare){
	HashMap *hashMapPtr;
	hashMapPtr->hash = hash;
	hashMapPtr->compare = compare;
	hashMapPtr->capacity = 10;
	hashMapPtr->buckets = (void *)calloc(10,sizeof(void *));
	return hashMapPtr;
};

int put(HashMap* map,void* key,void* value){
	
};
