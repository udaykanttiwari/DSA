#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Tree treeInstance;
int data[10]={1,2,3,4,5,6,7,8,9,10}; 

int compareInt(void* nodeData, void* parentData){
    return (*(int*)nodeData == *(int*)parentData);
};


int compareChar(void* nodeData, void* parentData){
    return (*(char*)nodeData == *(char*)parentData);
};

int compareDouble(void* nodeData, void* parentData){
    return (*(double *)nodeData == *(double *)parentData);
};
void test_1_to_create_tree_(){
	treeInstance= createTree(compareInt);
	ASSERT(treeInstance.root == NULL);		
};
void test_2_create_tree_and_insert_root_with_int_data(){
    Iterator* iterator;int result;
    Tree tree = createTree(compareInt);
    result = insertNode(&tree, NULL, &data[0]);
    iterator = getChildren(&tree, &data[0]);
    ASSERT(NULL == iterator->next(iterator));
    ASSERT(result == 1);
};
void test_3_create_tree_and_insert_root_with_a_char_data(){
    Iterator* iterator;
    Tree tree = createTree(compareChar);
    char data = 'z';
    int result = insertNode(&tree, NULL, &data);
    iterator = getChildren(&tree, &data);
    ASSERT(NULL == iterator->next(iterator));
    ASSERT(result == 1);
};

void test_4_create_tree_and_insert_root_with_double_type_of_data(){
    Iterator* iterator;
    Tree tree = createTree(compareDouble);
    double data = 10.0;
    int result = insertNode(&tree, NULL, &data);
    iterator = getChildren(&tree, &data);
    ASSERT(NULL == iterator->next(iterator));
    ASSERT(result == 1);
};

void test_5_insert_should_insert_a_child_to_root_node(){
    Iterator* iterator;
    Tree tree = createTree(compareInt);
    insertNode(&tree, NULL, &data[0]);
    insertNode(&tree, &data[0] , &data[1]);
    iterator = getChildren(&tree, &data[0]);
    ASSERT(&data[1] == iterator->next(iterator));
};

void test_6_insert_should_insert_two_children_to_root_node(){
    Iterator* iterator;
    Tree tree = createTree(compareInt);
    int result;
    result = insertNode(&tree, NULL, &data[0]);
    result = insertNode(&tree, &data[0],&data[1]);
    result = insertNode(&tree, &data[0],&data[2]);
    iterator = getChildren(&tree, &data[0]);
    ASSERT(&data[2] == iterator->next(iterator));
    ASSERT(&data[1] == iterator->next(iterator));
    ASSERT(result == 1);
};

void test_insert_should_insert_children_to_any_child(){
    Iterator* iterator;
    Tree tree = createTree(compareInt);
    int result;
    result = insertNode(&tree, NULL, &data[0]);
    result = insertNode(&tree, &data[0] ,&data[1]);
    result = insertNode(&tree, &data[1] ,&data[2]);
    result = insertNode(&tree,&data[2],&data[3]);
    result = insertNode(&tree,&data[3],&data[4]);
    result = insertNode(&tree,&data[4],&data[5]);
    iterator = getChildren(&tree, &data[3]);
	ASSERT(&data[4] == iterator->next(iterator));
    iterator = getChildren(&tree, &data[4]);
    ASSERT(&data[5] == iterator->next(iterator));
    ASSERT(result == 1);
};

void test_insert_should_not_insert_if_child_parents_is_not_availble(){
    Tree tree = createTree(compareInt	);
    int res;
    res = insertNode(&tree, NULL, &data[0]);
    res = insertNode(&tree, &data[0] , &data[1]);
    res = insertNode(&tree, &data[4] , &data[2]);
    ASSERT(res == 0);        
};

