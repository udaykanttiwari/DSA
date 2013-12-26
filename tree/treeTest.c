#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int comparator (void *fist, void *second){
	return 1;
};
Tree treeInstance;
void test_1_to_create_tree_(){
	treeInstance= createTree(comparator);
	ASSERT(treeInstance.root == NULL);		
};
void test_2_insert_node_in_tree(){
	int dataToInsert = 3;
	treeInstance = createTree(comparator);	
	insertNode(&treeInstance , NULL , &dataToInsert);
	
};
