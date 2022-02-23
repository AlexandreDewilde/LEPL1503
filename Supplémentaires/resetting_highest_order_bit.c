#include <stdint.h>
uint32_t reset_highestorder_strong_bit(uint32_t x) 
{
    for (int i=31; i >= 0; --i)
    {
        if (x & (1 << i)) return x & (~(1<<i));
    }
    return x;
}