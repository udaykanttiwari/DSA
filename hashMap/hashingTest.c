#include "testUtils.h"
#include "hashing.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct{
    int key;
    char value[50];
} Intern;

typedef char String[256];
Intern uday = {15412,"udaykant"};
Intern shital = {12342,"shital"};

int hashCodeGenerater(void* key){
	return  *(int*)key%10;
};

int comparater(void *first ,void *second){
	return *(int *)first - *(int *)second;
};

void test_createHashMap_shuld_create_hash_map(){
	HashMap hashMap;
	hashMap = createHashMap(hashCodeGenerater,comparater,10);
	ASSERT(hashMap.capacity == 10);
};
void test_put_element_to_bucket(){
	HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10);	
  void *data;
	ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
};

void test_put_element_to_bucket_and_get_element(){
	HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10);	
  void *data;void *result;
	ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
	ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
	result = get(&hashMap,&shital.key);
	ASSERT(strcmp(*(String*)result,"shital") == 0);
};

void test_put_element_to_bucket_and_get_element_udaykant(){
	HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10);	
  void *data;void *result;
	ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
	ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
	result = get(&hashMap,&uday.key);
	ASSERT(strcmp(*(String*)result,"udaykant") == 0);
};

void test_put_element_to_bucket_and_it_should_give_null(){
  HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10); 
  void *data;void *result;int key =12333;
  ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
  ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
  result = get(&hashMap,&key);
  ASSERT(result == NULL);
};

void test_put_element_to_bucket_remove_data_from_bucket(){
  HashMap hashMap = createHashMap(hashCodeGenerater,comparater,10); 
  void *data;int key =15412;
  ASSERT(put(&hashMap, &uday.key, &uday.value) == 1);
  ASSERT(put(&hashMap, &shital.key, &shital.value) == 1);
  ASSERT(1==removeHashData(&hashMap, &key));
  
};