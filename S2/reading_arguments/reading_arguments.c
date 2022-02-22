#include <stdio.h>


int main(int argc, char **argv){
    char **p;
    p = argv;
    p++;
    argc--;
    while(argc>2)
    {
        printf("%s ",*p);
        p+=2;
        argc-=2;
    }
    if(argc ==0 ){
        printf("\n");
    }
    if(argc >= 1){
        printf("%s\n",*p);
    }
    return 0;
}


// Pour compiler celui-ci, utilisez ceci : gcc reading_arguments.c -o myProg
// Ou alternativement utilisez "make" dans le terminal, qui l'exécutera aussi (grace au Makefile)