#include "tree.h"
#include <stdlib.h>
Tree createTree(compareFunc* compare){
        Tree tree;
        tree.root = NULL;
        tree.compare =  compare;
        return tree;
};

TreeNode* getNode(TreeNode* parentNode,void *data){
        TreeNode* node = calloc(1, sizeof(TreeNode));
        node->children = create();
        node->data = data;
        node->parent = parentNode;
        return node;
};

int insertNode(Tree* tree, void* parentData, void* data){
	TreeNode* parentNode;
    TreeNode* childNode;
    if(parentData == NULL){
       	tree->root = getNode(parentData,data);
        return 1;
    };
};

