#include <stdio.h>
#include <stdlib.h>


__attribute((__noreturn__))
void abort(void)
{
        #if defined(__is_libk)
                printf("kernel: panic: abort()\n");
                asm volatile("hlt");
        #else
                /* TODO(cork): raise SIGABRT or sum shit (syscall) */
                printf("abort()\n");
        #endif

        while (1){}
        __builtin_unreachable();
}