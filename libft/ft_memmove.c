 #include "libft.h"
 void *ft_memmove(void *dest, const void *orig, size_t n)
 {
    char *dst;
    char *src;

    dst = (char *)dest;
    src = (char *)orig;
    if (dest > orig)
    {
        while (n--)
            dst[n] = src[n];
    }
    else{
         while (n--)
            *(dst++) = *(src++);
    }
    return (dest);
 }