#include <stdlib.h>

void *calloc2(size_t nmemb, size_t size) 
{
    if (size == 0 || nmemb == 0) return NULL;
    char *ptr = malloc(nmemb*size);

    if (ptr == NULL) return NULL;
    // Or shorter version : if (!ptr) return NULL;
    // Questions : Which one is better practise ?

    for (int i = 0; i < nmemb; i++) ptr[i] = 0;
    return ptr;
}