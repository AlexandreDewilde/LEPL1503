#include <string.h>
/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
int pal(char *str) 
{
    if (str == NULL) return -1;
    size_t len = strlen(str);
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        if (str[i] == ' ')
        {
            i++;
            continue;
        }
        if (str[j] == ' ')
        {
            j--;
            continue;
        }
        if (str[i] != str[j]) return 0; 
        i++;
        j--;

    }
    return 1;
}