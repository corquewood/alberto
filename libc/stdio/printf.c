#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>



static bool print(const char *data, size_t len)
{
        const unsigned char *byte = (const unsigned char*) data;
        for (size_t i=0; i<len; ++i)
        {
                if (putchar(byte[i]) == EOF)
                {
                        return false;
                }
        }

        return true;
}


/* TODO(cork): support for %d and %x specifiers, EOF handling */
int printf(const char *restrict fmt, ...)
{
        va_list args;
        va_start(args, fmt);

        int written_chars = 0;

        for (const char *ptr = fmt; *ptr != '\0'; ++ptr)
        {
                if (*ptr != '%')
                {
                        print(ptr, 1);
                        written_chars++;
                        continue;
                }

                ptr++;
                
                switch(*ptr)
                {
                        case 'c':
                                char c = (char) va_arg(args, int);
                                putchar(c);
                                written_chars++;
                                break;

                        case 's':
                                const char *s = va_arg(args, const char*);

                                if (!s) s = "(NULL)";
                                print(s, strlen(s));
                                while (*s++) written_chars++;
                                break;

                        case '%':
                                putchar('%');
                                written_chars++;
                                break;

                        default:
                                putchar('%');
                                putchar(*ptr);
                                written_chars += 2;
                                break;
                }
        }

        va_end(args);
        return written_chars;
}