char* strcat(char* dest, char* src)
{
    int dst_len = 0;
    while (dest[dst_len] != '\0') dst_len++;

    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        char s = src[i];
        dest[dst_len + i] = s;
    }
    dest[dst_len + i] = '\0';
    return dest;
}