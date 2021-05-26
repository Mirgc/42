#include "libft.h"
void *ft_memcpy(void *dest, const void *orig, size_t n)
{
    char *src;
    char *dst;

    if (!dest && !orig)
        return (0);
    src = (char *)orig;
    dst = dest;
    while(n--)
        *(dst++) = *(src++);
    return (dest);
}