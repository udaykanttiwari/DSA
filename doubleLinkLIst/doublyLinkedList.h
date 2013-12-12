#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	void *data;
	struct Node* next;
	struct Node* pre;
}node;

typedef struct{
	node* head;
	int length;
}list;

list* create();
int insert(list* , int , void*);
void* Remove(list* , int index);
int findIndex(list*, void*);
int length(list*);