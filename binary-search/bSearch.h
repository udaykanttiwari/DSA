typedef int compare(const void *,const void *);

void* bSearch (void* key,void** base,
               int num, int  size,
               compare * cmp);
typedef char string[100];