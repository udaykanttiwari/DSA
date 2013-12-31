#include "hashing.h"
#include <stdlib.h>

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
    for (i = 0; i < capacity; ++i)
        base[i]=createBucket();
    hashMap.buckets = base;
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
    return 1;
};

void *get(HashMap *hashMap,void *key){
    int userKey=hashMap->getHashCode(key);
    Bucket * temp=(Bucket*)hashMap->buckets[userKey];
    Iterator *it = getIterator((temp->dList));
    HashData * hashData;
    while(it->hasNext(it)){
        hashData = it->next(it);
        if(hashMap->cmp(hashData->key,(void*)key)==0)
            return hashData->value;
    };
    return NULL;
};

int removeHashData(HashMap* hashMap, void* key){
    int count = 0;
    int userKey=hashMap->getHashCode(key);
    Bucket * temp = (Bucket*)hashMap->buckets[userKey];
    Iterator *it = getIterator((temp->dList));
    HashData * hashData;
    while(it->hasNext(it)){
        count++;        
        hashData = it->next(it);
        if(hashMap->cmp(hashData->key,(void*)key)==0) return Remove(temp->dList,count++);
    };
    return 0;
};

Iterator getKeys(HashMap* hashMap){
  int i;Bucket *temp;Iterator *it;
  HashData *hashData;
  List *keyList = (List *)malloc(sizeof(List));
  keyList = create();
   for(i = 0;i<hashMap->capacity;i++){
        temp = (Bucket*)hashMap->buckets[i];
        it= getIterator(temp->dList);        
        while(it->hasNext(it)){
            hashData = it->next(it);
         insert(keyList, keyList->length+1, hashData->key);    
        };
    };
    it = getIterator(keyList);
    return *it;
};

void disposeHash(HashMap* hashMap){
    Bucket * temp;
    int i;
    Iterator it;
    for(i = 0; i < hashMap->capacity; ++i)        {
        temp=(Bucket*)hashMap->buckets[i];
        free(temp->dList);
    };
    free(hashMap->buckets);
}
 