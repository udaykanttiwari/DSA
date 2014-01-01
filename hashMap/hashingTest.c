#include "testUtils.h"
#include "hashing.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct{
    int key;
    char value[50];
} Intern;

typedef char String[256];
Intern uday = {15412,"udaykant"};
Intern shital = {12342,"shital"};
Intern sandesh = {23124,"sandesh"};
Intern manish = {23125,"manish"};
Intern prateek = {12312,"prateek"};


int hashCodeGenerater(void* key,int capacity){
	return  *(int*)key%capacity;
};

int comparater(void *first ,void *second){
	return *(int *)first - *(int *)second;
};

void test_createHashMap_shuld_create_hash_map(){
	HashMap hashMap;
	hashMap = createHashMap(hashCodeGenerater,comparater,10);
	ASSERT(hashMap.capacity == 10);
  disposeHash(&hashMap);
};
void test_put_element_to_bucket(){
	HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10);	
  void *data;
	ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
  disposeHash(&hashMap);
};

void test_put_element_to_bucket_and_get_element(){
	HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10);	
  void *data;void *result;
	ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
	ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
	result = get(&hashMap,&shital.key);
	ASSERT(strcmp(*(String*)result,"shital") == 0);
  disposeHash(&hashMap);

};

void test_put_element_to_bucket_and_get_element_udaykant(){
	HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10);	
  void *data;void *result;
	ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
	ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
	result = get(&hashMap,&uday.key);
	ASSERT(strcmp(*(String*)result,"udaykant") == 0);
  disposeHash(&hashMap);

};

void test_put_element_to_bucket_and_it_should_give_null(){
  HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10); 
  void *data;void *result;int key =12333;
  ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
  ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
  result = get(&hashMap,&key);
  ASSERT(result == NULL);
  disposeHash(&hashMap);

};

void test_put_element_to_bucket_remove_data_from_bucket(){
  HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10); 
  void *data;int key =15412;
  ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
  ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
  ASSERT(1==removeHashData(&hashMap, &key));
  disposeHash(&hashMap);
};
void test_put_element_into_bucket_and_get_all_keys(){
  Iterator it;
  Iterator *itPtr;int count = 0;
  int* key[4];
  HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10); 
  ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
  ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
  ASSERT(put(&hashMap, &sandesh.key, &sandesh.value) == 1);
  ASSERT(put(&hashMap, &manish.key, &manish.value) == 1);
  it = getKeys(&hashMap);
  itPtr = &it;
  while(itPtr->hasNext(itPtr)){
      key[count] = itPtr->next(itPtr);
      count++;
  };
  ASSERT(*(int *)key[0] == 15412);
  ASSERT(*(int *)key[1] == 12342);
  ASSERT(*(int *)key[2] == 23124);
  ASSERT(*(int *)key[3] == 23125);
  disposeHash(&hashMap);
};
void test_put_element_to_bucket_and_rehash(){
  HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10); 
  void *data;void *result1,*result2,*result3;
  ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
  ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
  ASSERT(put(&hashMap, &prateek.key, &prateek.value) == 1);  
  result1 = get(&hashMap,&shital.key);
  result2 = get(&hashMap,&prateek.key);
  result3 = get(&hashMap,&uday.key);  
  ASSERT(strcmp(*(String*)result1,"shital") == 0);
  ASSERT(strcmp(*(String*)result2,"prateek") == 0);
  ASSERT(strcmp(*(String*)result3,"udaykant") == 0);
  disposeHash(&hashMap);
};
