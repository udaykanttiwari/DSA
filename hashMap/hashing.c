#include "hashing.h"
#include <stdlib.h>
#include "./include/doublyLinkedList.h"
typedef char string[256];

typedef struct{
    void* key;
    void* value;
}HashData;

typedef struct{
    List *dList;
}Bucket;

Bucket* createBucket(){
	Bucket* bucket =malloc(sizeof(Bucket));
	bucket->dList = create();
	return bucket;
};
void *createList(int capacity){
	void **base;
	return base = calloc(sizeof(void*),capacity);
};
HashMap createHashMap(HashCodeGenerator *getHashCode, compareKeys *cmp,int capacity){
	Bucket start;
	HashMap hashMap;int i;
	void **base = createList(capacity);
    for (i 	= 0; i < capacity; ++i)
        base[i]=createBucket();
    hashMap.buckets = 	base;
    hashMap.getHashCode = getHashCode;
	hashMap.cmp = cmp;
	hashMap.capacity = capacity;
	return hashMap;
};
int put(HashMap* hashMap,void* key,void* value){
    int userKey=hashMap->getHashCode(key);
    Iterator *it;
    HashData* data1;
    Bucket * temp=(Bucket*)hashMap->buckets[userKey];
    HashData *hashData=malloc(sizeof(HashData));
    hashData->value=(void*)value;
    hashData->key=(void*)key;
    insert(temp->dList, temp->dList->length+1, hashData);
    it = getIterator((temp->dList));
    data1 = it->next(it);
    return 1;
};
