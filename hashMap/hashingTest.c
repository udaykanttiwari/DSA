#include "testUtils.h"
#include "hashing.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int hashCodeGenerater(void* key){
	int bucketIndex;
	printf("key is %d", *(int*)key);
	bucketIndex =  *(int*)key % 10;
	return bucketIndex;
};

int comparater(void *first ,void *second){
	return 1;
};

void test_createHashMap_shuld_create_hash_map(){
	HashMap *hashMapPtr;
	char a[1024];	
	hashMapPtr = createHashMap(hashCodeGenerater,comparater);
	ASSERT(hashMapPtr->capacity == 10);
};
