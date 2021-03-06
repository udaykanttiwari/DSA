#include "hashing.h"
#include <stdlib.h>
Iterator getValues(HashMap* hashMap);

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

void **assignListToeveryBucket(int capacity){
    int i; 
    void **base = createList(capacity);
    for (i = 0; i < capacity; ++i)
    base[i]=createBucket();
    return base;
};

HashMap createHashMap(HashCodeGenerator *getHashCode, compareKeys *cmp,int capacity){
	Bucket start;
	HashMap hashMap;int i;
	hashMap.buckets = assignListToeveryBucket(capacity);
    hashMap.getHashCode = getHashCode;
	hashMap.cmp = cmp;
	hashMap.capacity = capacity;
	return hashMap;
};

void ** reHashing(HashMap *hashMap){
    int i;void **base;
    hashMap->capacity = hashMap->capacity*2;
    free(hashMap->buckets);
    hashMap->buckets = assignListToeveryBucket(hashMap->capacity);;
    return hashMap->buckets;
};

HashData* createHashData(void *key ,void *value){
    HashData *hashData;
    hashData=malloc(sizeof(HashData));
    hashData->value=(void*)value;
    hashData->key=(void*)key;
    return hashData;
};

void executeIterator(HashMap *hashMap,Iterator it,HashData *hashData,void *key,void *value){
    Iterator *itPtr = &it;
    put(hashMap,key,value);
    while(itPtr->hasNext(itPtr)){
        hashData = itPtr->next(itPtr);
        put(hashMap,hashData->key,hashData->value);
    };
};

void checkForRehashing(HashMap *hashMap,Bucket *temp,HashData *hashData,void *key,void *value){
    Iterator it,*itPtr;
    if(temp->dList->length+1>2){
    it = getValues(hashMap);
    itPtr = &it;
    hashMap->buckets = reHashing(hashMap);
    executeIterator(hashMap,it,hashData,key,value);
    };
    return ;
};

int put(HashMap* hashMap,void* key,void* value){
    int userKey=hashMap->getHashCode(key,hashMap->capacity);
    Bucket * temp; HashData *hashData;
    temp=(Bucket*)hashMap->buckets[userKey];
    hashData= createHashData(key,value);
    checkForRehashing(hashMap,temp,hashData,key,value);    
    insert(temp->dList, temp->dList->length+1, hashData);  
    return 1;
};

void *getValue(HashMap *hashMap,Bucket *temp,void *key){
    HashData * hashData;    
    Iterator *it = getIterator((temp->dList));    
    while(it->hasNext(it)){
        hashData = it->next(it);
        if(hashMap->cmp(hashData->key,(void*)key)==0)
            return hashData->value;
    };
    return NULL;
};

void *get(HashMap *hashMap,void *key){
    int userKey=hashMap->getHashCode(key,hashMap->capacity);
    Bucket * temp=(Bucket*)hashMap->buckets[userKey];
    return getValue(hashMap,temp,key);
};
int executeIteratorForRemoveValue(HashMap* hashMap, void* key,Bucket *temp){
    HashData * hashData; int count =0;   
    Iterator *it = getIterator((temp->dList));    
    while(it->hasNext(it)){
        count++;        
        hashData = it->next(it);
        if(hashMap->cmp(hashData->key,(void*)key)==0) return Remove(temp->dList,count++);
    };
    return 0;
};

int removeHashData(HashMap* hashMap, void* key){
    int userKey=hashMap->getHashCode(key,hashMap->capacity);
    Bucket * temp = (Bucket*)hashMap->buckets[userKey];
    return executeIteratorForRemoveValue(hashMap,key,temp);
};

List *insertKeysIntoList(HashMap *hashMap,List *list){
    int i;Bucket *temp;Iterator *it;HashData *hashData;
    for(i = 0;i<hashMap->capacity;i++){
        temp = (Bucket*)hashMap->buckets[i];
        it= getIterator(temp->dList);        
        while(it->hasNext(it)){
            hashData = it->next(it);
            insert(list, list->length+1, hashData->key);    
        };
    };
    return list;
};

List *insertValuesIntoList(HashMap *hashMap,List *list){
    int i;Bucket *temp;Iterator *it;HashData *hashData;
    for(i = 0;i<hashMap->capacity;i++){
        temp = (Bucket*)hashMap->buckets[i];
        it= getIterator(temp->dList);        
        while(it->hasNext(it)){
            hashData = it->next(it);
            insert(list, list->length+1, hashData);    
        };
    };
    return list;
};

Iterator getKeys(HashMap* hashMap){
    Iterator *it;
    List *keyList = (List *)malloc(sizeof(List));
    keyList = create();
    keyList = insertKeysIntoList(hashMap,keyList);
    it = getIterator(keyList);
    return *it;    
};

Iterator getValues(HashMap* hashMap){
    Iterator *it;
    List *ValuesList = (List *)malloc(sizeof(List));
    ValuesList = create();
    ValuesList = insertValuesIntoList(hashMap,ValuesList);
    it = getIterator(ValuesList);
    return *it;  
};

void disposeHash(HashMap* hashMap){
    Bucket * temp;
    int i;
    Iterator it;
    for(i = 0; i < hashMap->capacity; i++){
        temp=(Bucket*)hashMap->buckets[i];
        free(temp->dList);
    };
    free(hashMap->buckets);
};
 