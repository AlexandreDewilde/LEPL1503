#include <stdint.h>
#include <stdbool.h>
/*
 * @pre 0<= pos < 64
 */
uint64_t set_bit(uint64_t x, int pos, bool value) 
{
    int mask = 1 << pos;
    if (value) return x | mask;
    return x & (~mask);
}