#include <stdlib.h>
/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s) 
{
    void* ptr;
    for (int i=0; i < 10; i++)
    {
        ptr = malloc(s);
        if (ptr != NULL) return ptr;
        // Or shorter if (!ptr) return ptr;
        sleep(5);
    }
    return NULL;
}