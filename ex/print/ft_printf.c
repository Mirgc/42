#include "ft_printf.h"

int check_flag(char s, va_list arg)
{
    int c_count;

    c_count = 0;
    if (s == 's')
        c_count += ft_putstr(va_arg(arg, char *));
    if (s == 'd' || s == 'i')
        c_count += ft_putnbr(va_arg(arg, int));
    if (s == 'x')
        c_count += ft_puthex(va_arg(arg, unsigned int), c_count);
    return (c_count);
}

int ft_printf(const char *orig, ...)
{
    va_list arg;
    char    *str;
    int     c_count;

    va_start(arg, orig);
    str = (char *)orig;
    c_count = 0;
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            c_count += check_flag(*str, arg);
            str++;
        }
        else
        {
            c_count += ft_putchar(*str);
            str++;
        }
    }
    va_end(arg);
    return (c_count);
}
