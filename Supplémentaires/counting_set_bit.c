#include <stdint.h>
uint8_t nbits(uint32_t n) 
{
    // GCC possede une built in pour compter le bit a 1, cette fonction vas essayer d'utiliser le CPU et sera donc la facon la plus rapide:
    return __builtin_popcount(n); // Attention ne marche pas avec d'autre compiler que gcc
    
    // La maniere attendu est probablement celle ci : 
    // int c = 0;
    // while (n)
    // {
    //     c += n & 1;
    //     n >>= 1;
    // }
    // return c;
}