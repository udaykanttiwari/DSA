#include "./include/doublyLinkedList.h"

typedef int (*compareFptr)(void* first, void* second);
typedef int (*HashCodeGenerator)(void* key);

typedef	struct {
	void* buckets;	
	int capacity;
	HashCodeGenerator hash;
    compareFptr compare;
}HashMap;

HashMap* createHashMap(HashCodeGenerator hash, compareFptr compare);