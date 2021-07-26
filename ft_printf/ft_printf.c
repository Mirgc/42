#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str_arg)
{
	while (*str_arg)
	{
		ft_putchar(*str_arg);
		str_arg++;
	}
}

void	ft_putnbr(long num)
{
	if (num == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		num = 147483648;
	}
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
}

void	ft_puthex(unsigned int num, int cap)
{
	int	tmp;

	if (num > 0)
	{
		ft_puthex(num / 16, cap);
		tmp = num % 16;
		if (tmp > 9)
		{
			if (cap == 0)
				ft_putchar((tmp - 10) + 'a');
			else
				ft_putchar((tmp - 10) + 'A');
		}
		else
			ft_putchar(tmp + '0');
	}
}

void	check_flag(char s, va_list arg)
{
	if (s == 'c')
		ft_putchar((char)va_arg(arg, int));
	if (s == 's')
		ft_putstr(va_arg(arg, char *));
	if (s == 'p')
	{
		write(1, "0x7ffe", 6);
		ft_puthex(va_arg(arg, unsigned long long), 0);
	}
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(arg, int));
	if (s == 'u')
		ft_putnbr(va_arg(arg, unsigned int));
	if (s == 'x')
		ft_puthex(va_arg(arg, unsigned int), 0);
	if (s == 'X')
		ft_puthex(va_arg(arg, unsigned int), 1);
	if (s == '%')
		ft_putchar('%');
}

int	ft_printf(const char *orig, ...)
{
	va_list	arg;
	char	*str;

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
	return (0);
}
