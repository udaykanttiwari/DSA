void* bSearch (const void* key, const void* base,
               int num, int  size,
               int (*compare)(const void*,const void*));
typedef int compare(const void *,const void *);
typedef char string[100];