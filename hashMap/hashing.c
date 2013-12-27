#include "hashing.h"

HashMap* create_hash_map(HashCodeGenerarater* hashCodeGenerarater,Compare *compareter){
	
	HashMap *hashMapPtr;
	hashMapPtr->HashCodeGenerarater = hashCodeGenerarater;
	hashMapPtr->Compare = compareter;
	hashMapPtr->bucket = (list *)calloc(10,sizeof(void *));
};
