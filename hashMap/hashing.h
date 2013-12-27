#include "./include/arrayList.h"
#include "./include/doublyLinkedLish.h"
typedef int HashCodeGenerarater(void *key,int sizeofBucket);

typedef int Compare(void *first,void *second);

typedef struct{
	HashCodeGenerarater hashCodeGenerarater,
	Compare comparater,
	list *bucket
}HashMap;

HashMap create_hash_map(HashCodeGenerarater* hashCodeGenerarater,Compare *comparater);

put(HashMap * hashMapPtr, void *key , void *value);

void *get(HashMap *hashMapPtr,void *key);

int remove (HashMap *hashMapPtr,void *key);

iterater keys(HashMap *);

dispose();