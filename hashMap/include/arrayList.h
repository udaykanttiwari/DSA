typedef struct{
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int (*compare) (void *key, void* element);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

//void dispose(ArrayList *list);

int  remove(ArrayList * list,int index);

int search(ArrayList* list, void*data, compare compareFunc);

