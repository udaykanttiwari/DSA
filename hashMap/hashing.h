#include "./include/doublyLinkedList.h"

typedef int compareKeys(void* first, void* second);
typedef int HashCodeGenerator(void* key,int capacity);

typedef	struct{
	void** buckets;	
	HashCodeGenerator *getHashCode;
    compareKeys *cmp;
    int capacity;
}HashMap;

HashMap createHashMap(HashCodeGenerator *getHashCode, compareKeys *cmp,int capacity);
int put(HashMap* hashMap,void* key,void* value);
void *get(HashMap *hashMap,void *key);
int removeHashData(HashMap* hashMap, void* kay);
Iterator getKeys(HashMap* hashMap);
void disposeHash(HashMap* hashMap);