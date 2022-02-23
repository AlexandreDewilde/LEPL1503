#include <stdint.h>

uint32_t cycle_bits(uint32_t x, uint8_t n) 
{
    int r = x << n;
    return (x >> (32-n)) | r;
}