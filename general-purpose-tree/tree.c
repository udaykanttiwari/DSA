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
void insertChildern(TreeNode *treeNode,List *listOfChildren){
    Iterator *iteratorChild;
     if(treeNode->children->head != NULL){
        iteratorChild = getIterator(treeNode->children);
        while(iteratorChild->hasNext(iteratorChild)){
            insert(listOfChildren, listOfChildren->length + 1, iteratorChild->next(iteratorChild));
        };
    };
    return ;
};

TreeNode* compareNodes(List* list, compareFunc* compareFunc, void* parentData){
    Iterator *iterator = getIterator(list);
    TreeNode* treeNode,result;
    List *listOfChildren = create();
    if(0 == iterator->hasNext(iterator)){
            return NULL;
    };
    insertChildern(treeNode,listOfChildren);
    while(iterator->hasNext(iterator)){
        treeNode = (TreeNode*)iterator->next(iterator);
        if(compareFunc(treeNode->data,parentData)){
            return treeNode;
        };       
    };
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

int getChildIndex(List* list,void* childData, compareFunc* compareFunc){
    Iterator* iterator = getIterator(list);
    TreeNode *ptNode;
    int result;
    while(iterator->hasNext(iterator)){
        ptNode = iterator->next(iterator);
        result = compareFunc(ptNode->data, childData);
        if(result) return iterator->currentPosition;
    }
    return -1;
};
int deleteNode(Tree* tree, void* dataToDelete){
    TreeNode* parentNode;
    TreeNode* nodeToSearch;
    int index;
    if(tree->root == NULL) return 0;
    parentNode = tree->root;
    if(((List*)(parentNode->children))->head == NULL){
            tree->root = NULL;
            return 1;
    }
    nodeToSearch = searchNode(tree,dataToDelete);
    parentNode = nodeToSearch->parent;
    if(nodeToSearch == NULL)return 0;
    if(nodeToSearch->children->head != NULL) return 0;
    index = getChildIndex(parentNode->children,dataToDelete,tree->compare);
    if(index == -1) return 0;
    return Remove(parentNode->children,index);
};
void DisposeTree(List *list){
    TreeNode* temp;
    Iterator *it = getIterator(list);
    while(it->hasNext(it)){
        temp = it->next(it);
        if(NULL != temp->children->head){
            DisposeTree(temp->children);
        }
        dispose(temp->children);
    };
};