#include "hashing.h"

HashMap* createHashMap(HashCodeGenerator *getHashCode, compareFptr *compare){
	HashMap *hashMapPtr;
	hashMapPtr->getHashCode = HashCodeGenerator;
	hashMapPtr->compare = compare;
	hashMapPtr->capacity = 10;
	hashMapPtr->buckets = (void *)calloc(10,sizeof(void *));
	return hashMapPtr;
};

int put(HashMap* map,void* key,void* value){
	int index= map->getHashCode(key);
};
