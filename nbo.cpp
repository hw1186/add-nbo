#include "nbo.h"

uint32_t nbo_to_host(uint32_t* ptr){
    uint32_t a = *ptr;
    uint32_t a1 = (a & 0xff000000) >> 24;
    uint32_t a2 = (a & 0x00ff0000) >> 8;
    uint32_t a3 = (a & 0x0000ff00) << 8;
    uint32_t a4 = (a & 0x000000ff) << 24;

    return a1 | a2 | a3 | a4;
}

