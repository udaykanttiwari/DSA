typedef int compare(void *first,void *second);
void merge(void *left,void *right,void *base,int lengthOfleft,int lengthofRight,compare *cmp,int typeSize);
void mergeSort(void *base,int typeSize,int length,compare *cmp);