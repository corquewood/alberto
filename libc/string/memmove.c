#include <string.h>


void *memmove(void *dstptr, const void* srcptr, size_t size)
{
        unsigned char *dst = (unsigned char*) dstptr;
        unsigned char *src = (unsigned char*) srcptr;


        if (dst < src)
        {      
                 /* copy forward */
                for (size_t i=0; i<size; ++i)
                        dst[i] = src[i];
        } else 
        {       
                /* copy backward to prevent overwriting */
                for (size_t i=size; i!=0; --i)
                        dst[i-1] = src[i-1];
        }

        return dstptr;
}