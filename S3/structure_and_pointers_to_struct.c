#include <stdlib.h>


typedef struct product {
    char *name;
    double price;
} product_t;


/*
 * @ptrProd != NULL
 * @return: the price of the product ptrProd
 */
double getPtrPrice(product_t *ptrProd)
{
    // Dans ce cas ci on utilise -> et non . car ce que l'on as est un pointeur vers la variable ptrProd
    // Si on voulait utiliser la notation avec . on pourrait faire comme ça:
    // return (*ptrProd).price;
    return ptrProd->price;

}

/*
 * @return: the price of the product prod
 */
double getPrice(product_t prod)
{
    // Cas opposé au précédent, on n'as plus un pointeur
    // Si on voulait faire comme le précédent on pourrait faire :
    // return (&prod)->price;
    return prod.price;
}


/*
 * ptrProd != NULL
 * @name in ptrProd != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getPtrName(product_t *ptrProd)
{
    char* nameRef = ptrProd->name;
    char* name = malloc(strlen(nameRef) + 1);
    if (name == NULL) return NULL;
    // if (!name) return NULL;
    strcpy(name, nameRef);
    return name;
}

/*
 * @name in prod != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getName(product_t prod)
{
    char* nameRef = prod.name;
    char* name = malloc(strlen(nameRef) + 1);
    if (name == NULL) return NULL;
    // if (!name) return NULL;
    strcpy(name, nameRef);
    return name;
}

/*
 * @ptrProd != NULL
 * @name in ptrProd != NULL
 * @name in prod != NULL
 * @return: 1 if the two products are the same, i.e., they have the same price and the same name
 */
int prodEquals(product_t *ptrProd, product_t prod)
{
    // ATTENTION ICI, lorsque l'on compare deux string à utiliser strcmp == compare la valeur des deux pointeurs
    return ptrProd->price == prod.price && strcmp(ptrProd->name, prod.name) == 0;
}