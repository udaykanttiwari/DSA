#include "testUtils.h"
#include "hashing.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int hashCodeGenerater(void* key){
	int bucketIndex;
	bucketIndex =  *(int*)key % 10;
	return bucketIndex;
};

int comparater(void *first ,void *second){
	return 1;
};

void test_createHashMap_shuld_create_hash_map(){
	HashMap *hashMapPtr;	
	printf("COming\n");
	hashMapPtr = createHashMap(hashCodeGenerater,comparater);
	ASSERT(hashMapPtr->capacity == 10);
};
void test_put_should_put_value_into_bucket(){
	HashMap *hashMapPtr;	
	printf("COming\n");
	hashMapPtr = createHashMap(hashCodeGenerater,comparater);
	put(hashMapPtr,15,15);
};
