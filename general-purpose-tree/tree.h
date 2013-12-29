#include "./include/doublyLinkedList.h"

typedef int compareFunc (void* frist, void* second);

typedef struct TreeNode{
    void* data;
    struct TreeNode* parent;
    List* children;
}TreeNode;

typedef struct{
   TreeNode* root;
   compareFunc *compare;
}Tree;

Tree createTree(compareFunc* compare);
Tree createTree(compareFunc* compare);
int insertNode(Tree* treePtr, void* parentData, void* data);
int deleteNode(Tree* treePtr, void* dataToDelete);
TreeNode* searchNode(Tree* treePtr,void* data);
Iterator* getChildren(Tree* treePtr, void *parentData);

