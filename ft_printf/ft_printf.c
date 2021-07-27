#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str_arg)
{
	int	c_count;

	c_count = 0;
	while (*str_arg)
	{
		c_count += ft_putchar(*str_arg);
		str_arg++;
	}
	return (c_count);
}

int	ft_putnbr(long num)
{
	int	c_count;

	c_count = 0;
	if (num == -2147483648)
	{
		c_count += ft_putstr("-2");
		num = 147483648;
	}
	if (num < 0)
	{
		c_count += ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		c_count += ft_putchar(num + '0');
	return (c_count);
}

int	ft_puthex(unsigned long long num, int cap)
{
	int	tmp;
	int	c_count;

	c_count = 0;
	if (num > 0)
	{
		ft_puthex(num / 16, cap);
		tmp = num % 16;
		if (tmp > 9)
		{
			if (cap == 0)
				c_count += ft_putchar((tmp - 10) + 'a');
			else
				c_count += ft_putchar((tmp - 10) + 'A');
		}
		else
			c_count += ft_putchar(tmp + '0');
	}
	return(c_count);
}

int	check_flag(char s, va_list arg)
{
	int c_count;

	c_count = 0;
	if (s == 'c')
		c_count += ft_putchar((char)va_arg(arg, int));
	if (s == 's')
		c_count += ft_putstr(va_arg(arg, char *));
	if (s == 'p')
	{
		c_count += ft_putstr("0x");
		c_count += ft_puthex(va_arg(arg, unsigned long long), 0);
	}
	if (s == 'd' || s == 'i')
		c_count += ft_putnbr(va_arg(arg, int));
	if (s == 'u')
		c_count += ft_putnbr(va_arg(arg, unsigned int));
	if (s == 'x')
		c_count += ft_puthex(va_arg(arg, unsigned int), 0);
	if (s == 'X')
		c_count += ft_puthex(va_arg(arg, unsigned int), 1);
	if (s == '%')
		c_count += ft_putchar('%');
	return (c_count);
}

int	ft_printf(const char *orig, ...)
{
	va_list	arg;
	char	*str;
	int	c_count;

	va_start(arg, orig);
	str = (char *)orig;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			c_count += check_flag(*str, arg);
			str++;
		}
		c_count += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (c_count);
}
