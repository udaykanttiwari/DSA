
typedef int compareKeys(void* first, void* second);
typedef int HashCodeGenerator(void* key);

typedef	struct{
	void** buckets;	
	HashCodeGenerator *getHashCode;
    compareKeys *cmp;
    int capacity;
}HashMap;

HashMap createHashMap(HashCodeGenerator *getHashCode, compareKeys *cmp,int capacity);
int put(HashMap* hashMap,void* key,void* value);