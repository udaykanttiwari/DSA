typedef int compareFunc(void *first,void *second);
void bubbleSort(void *element,int numberOfElements,int typeSize,compareFunc *compare);