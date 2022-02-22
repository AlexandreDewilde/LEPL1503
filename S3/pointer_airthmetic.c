
int first(void *ptr) 
{
    return *(int*)(ptr+12);

    // à ma premiere approche, ne connaissant pas/peu les pointeurs j'avais fais ceci 
    // return (int) ((int *) ptr)[3];
}

char second(void *ptr) 
{
    return *(char*)(ptr+6);

    // Premiere approche
    // return (char) ((char *) ptr)[6];
}

int third(void *ptr)
{
    return *(int*)(ptr+45);
}