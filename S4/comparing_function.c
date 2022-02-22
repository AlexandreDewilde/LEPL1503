#include <stdint.h>

int cmp_func(uint8_t f1(uint8_t a), uint8_t f2(uint8_t a))
{
    for (int i=0;i<256;i++)
    {
        if (f1(i) != f2(i)) return 0;
    }
    return 1;
}