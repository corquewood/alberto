#include <string.h>


void *memset(void *blockptr, int value, size_t size)
{
        /* convert blockptr to a byte ptr */
        unsigned char *block = (unsigned char*) blockptr;
        for (size_t i=0; i<size; ++i)
                block[i] = (unsigned char) value;

        return blockptr;
}