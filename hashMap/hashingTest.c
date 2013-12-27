#include "testUtils.h"
#include "hashing.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int hashCodeGenerarater(void &key,int bucketSize){
	int bucketIndex =  (int*)key/bucketSize;
	return bucketIndex;
};

int comparater(void *first ,void *second){
	return 1;
};

hashMap *hashMapPtr;

void test_createHashMap_shuld_create_hash_map(){
	hashMapPtr= create_hash_map(hashCodeGenerarater,comparater);
};
