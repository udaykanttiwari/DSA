#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Tree treeInstance;
int data[10]={1,2,3,4,5,6,7,8,9,10}; 

int compareInt(void* nodeData, void* parentData){
    return (*(int*)nodeData == *(int*)parentData);
};

void test_1_to_create_tree_(){
	treeInstance= createTree(compareInt);
	ASSERT(treeInstance.root == NULL);		
};
void test_2create_tree_and_insert_root_with_int_data(){
    Iterator* iterator;int result;
    Tree tree = createTree(compareInt);
    result = insertNode(&tree, NULL, &data[0]);
    iterator = getChildren(&tree, &data[0]);
    ASSERT(NULL == iterator->next(iterator));
    ASSERT(result == 1);
};
void test_to_create_tree_and_insert_root_with_an_char_data(){
    Iterator* iterator;
    Tree tree = createTree(compareChar);
    char data = 'z';
    int res = insertNode(&tree, NULL, &data);
    iterator = getChildren(&tree, &data);
    ASSERT(NULL == iterator->next(iterator));
    ASSERT(res == 1);
}