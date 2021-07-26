#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
        write(0, &c, 1);
}

void ft_putstr(char *str_arg)
{
        while(*str_arg)
        {
                ft_putchar(*str_arg);
                str_arg++;
        }
}

void check_flag(char s, va_list arg)
{
        if (s == 'c')
                ft_putchar((char)va_arg(arg, int));
        if (s == 's')
                ft_putstr(va_arg(arg, char *));
        if (s == 'p')
                write(0, va_arg(arg, unsigned long long), 16);
}

int ft_printf(const char *orig, ...)
{
        va_list arg;
        char    *str;
        va_start(arg, orig);

        str = (char *)orig;
        while (*str)
        {
                if (*str == '%')
                {
                        str++;
                        check_flag(*str, arg);
                        str++;
                }
                ft_putchar(*str);
                str++;
        }
        va_end(arg);
        free(str);
        return (0);
}
