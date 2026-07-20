#include <string.h>


int memcmp(const void *ptr1, const void *ptr2, size_t size)
{
        /* convert ptrs to byte ptrs for array indexing*/
        const unsigned char *one = (const unsigned char*) ptr1;
        const unsigned char *two = (const unsigned char*) ptr2;

        for (size_t i=0; i<size; ++i)
        {
                if (one[i] > two[i])
                        return 1;
                else if (one[i] < two[i])
                        return -1;
        }

        return 0;
}