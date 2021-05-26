#include "libft.h"
char *ft_strrchr(const char *str, int c)
{
    char ch;
    int i;

    ch = (char)c;
    i = 0;
    while (*str)
    {
        str++;
        i++;
    }
    while (i != 0)
    {
        if (*str == ch)
            return((char *)str);
        i--;
        str--;
    }
    return (0);
}