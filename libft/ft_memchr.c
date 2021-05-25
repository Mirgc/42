#include "libft.h"
void *memchr(const void *str, int c, size_t n)
{
    char *s;
    int i;

    s = (char *)str;
    i = 0;
    while(n-- && *s)
    {
        if (s[i] == (char)c)
            return ((void *)s + i);
        i++;
    }
    return(0);
}