#include "testUtils.h"
#include "hashing.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct{
    int key;
    char value[50];
} Intern;

typedef char String[256];
Intern uday = {15412,"udaykant"};

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
  	ASSERT(put(&hashMap, &uday.key, &uday.value)== 1);
}
	