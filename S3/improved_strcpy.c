#include <stdlib.h>


/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src)
{
    char *ans = malloc((strlen(src) + 1)*sizeof(char));
    if (!ans) return NULL;
    // Equivalent to :
    // if (ans == NULL) return NULL;
    int i;
    for (i = 0; i < strlen(src); i++)
    {
        ans[i] = src[i];
    }
    ans[i] = '\0';
    char *stack = ans;
    return stack;
}
