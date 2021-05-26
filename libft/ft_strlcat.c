#include "libft.h"
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t  res;
    
    i = 0;
    while (dst[i] != '\0')
        i++;
    res = 0;
    while (src[res] != '\0')
        res++;
    if (dstsize <= i)
        res += dstsize;
    else
        res += i;
    while (*src && i + 1 < dstsize)
    {
        *(dst + i)= *(src++);
        i++;
    }
    dst[i] = '\0';
    return (res);
}