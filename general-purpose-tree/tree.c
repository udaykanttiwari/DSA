#include "tree.h"
#include <stdlib.h>

Tree createTree(compareFunc* compare){
    Tree tree;
    tree.root = NULL;
    tree.compare =  compare;
    return tree;
};
TreeNode* getNode(TreeNode* parentNode,void *data){
    TreeNode* node = calloc(1,sizeof(TreeNode));
    node->children = create();
    node->data = data;
    node->parent = parentNode;
    return node;
};

TreeNode* compareNodes(List* list, compareFunc* compareFunc, void* parentData){
    Iterator* iterator = getIterator(list);
    TreeNode* treeNode,result;
    Iterator* iteratorChild;
    List *listOfChildren = create();
    if (0 == iterator->hasNext(iterator)){
            return NULL;
    }
    while(iterator->hasNext(iterator)){
        treeNode = (TreeNode*)iterator->next(iterator);
        if(compareFunc(treeNode->data,parentData)){
            return treeNode;
        }
        if(treeNode->children->head != NULL){
            iteratorChild = getIterator(treeNode->children);
            while(iteratorChild->hasNext(iteratorChild)){
                insert(listOfChildren, listOfChildren->length + 1, iteratorChild->next(iteratorChild));
                }
        }
    }
    return compareNodes(listOfChildren,compareFunc,parentData);
};

TreeNode* searchNode(Tree* treePtr,void* parentData){
    TreeNode* parent;
    TreeNode* root = treePtr->root;
    if(NULL == root)
        return NULL;
    if(treePtr->compare(root->data, parentData)) return root;
    parent = compareNodes(root->children, treePtr->compare, parentData);
    return parent;
};

int insertNode(Tree* treePtr, void* parentData, void* data){
    TreeNode* parentNode;
    TreeNode* childNode;        
    if(parentData == NULL && treePtr->root == NULL){
        treePtr->root = getNode(parentData,data);
        return 1;
    };
    parentNode = searchNode(treePtr,parentData);
    if(parentNode == NULL) return 0;      
    childNode = getNode(parentNode,data);
    return insert(parentNode->children,1,childNode);
};

void* getNextChildData(Iterator* iterator){
    TreeNode *node;
    Iterator* treeIterator = getIterator(iterator->list);
    treeIterator->currentPosition = iterator->currentPosition;
    node = treeIterator->next(treeIterator);
    if(!node) return node;
    iterator->currentPosition++;
    return node->data;
};


Iterator* getChildren(Tree* treePtr, void *parentData){
    TreeNode* parentNode = searchNode(treePtr, parentData);
    Iterator* iterator;
    if(!parentNode){
        iterator = getIterator(NULL);
        return iterator;
    };
    iterator = getIterator(parentNode->children);
    iterator->next = &getNextChildData;
    return iterator;
};