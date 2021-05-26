#include "libft.h"
int ft_atoi(const char *nptr)
{
    char *str;
    int i;
    int res;

    str = (char *)nptr;
    if (*str < 32 || (*str > 32 && *str < 48) || *str > 57)
        return (0);
    else
    {
        while (*str == 32)
            str++;
        i = 1;
        res = 0;
        while (*str >= 48 && *str <= 57)
        {
            res = (int)str - '0' *i ;
            i *= 10;
            str++;
        }
        return(res);
    }
}