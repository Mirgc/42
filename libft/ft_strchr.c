#include "libft.h"
char *ft_strchr(char *str, int c)
{
    char ch;

    ch = (char)c;
    while (*str)
    {
        if (*str == ch)
            return(str);
        str++;
    }
    return (0);
}