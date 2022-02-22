#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int eq(int a, int b) { return (a != b); }

int ge(int a, int b) {return a < b;}

int gt(int a, int b) {return a <= b;}

int le(int a, int b) {return a > b;}

int lt(int a, int b) {return a >= b;}

int ne(int a, int b) {return a == b;}

int exectute(int a, int b, char* arg)
{
    if (strcmp(arg, "-eq") == 0) return eq(a, b);
    if (strcmp(arg, "-ge") == 0) return ge(a, b);
    if (strcmp(arg, "-gt") == 0) return gt(a, b);
    if (strcmp(arg, "-le") == 0) return le(a, b);
    if (strcmp(arg, "-lt") == 0) return lt(a, b);
    if (strcmp(arg, "-ne") == 0) return ne(a, b);
}



int main(int argc, char **argv)
{
    int a = atoi(argv[1]);
    char* operator = argv[2];
    int b = atoi(argv[3]);
    return exectute(a, b, operator);
}