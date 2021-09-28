#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);  
}

int	ft_putstr(char *str)
{
	int c_count;

	c_count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while(*str)
	{
		c_count += ft_putchar(*str);
		str++;
	}
	return (c_count);
}

int ft_len(int nbr, int base)
{
	int c_count;

	c_count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		c_count++;
	while (nbr != 0)
	{
		nbr /= base;
		c_count++;
	}
	return (c_count);
}

int ft_putnbr(long nbr)
{
	int c_count;

	c_count = 0;
	if (nbr < 0)
	{
		c_count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
	c_count += ft_len(nbr, 10);
	return (c_count);
}

int ft_puthex(unsigned long nbr, int c_count)
{
	int tmp;
	static int c_sta;

	c_sta = 0;
	if (nbr == 0 && (c_count == 0 || c_count == 2))
		c_sta += ft_putchar('0');
	if (nbr > 0)
	{
		c_count = 1;
		ft_puthex(nbr / 16, c_count);
		tmp = nbr % 16;
		if (tmp > 9)
			c_sta += ft_putchar((tmp - 10) + 'a');
		else
			c_sta += ft_putchar(tmp + '0');
	}
	return (c_sta);
}

int check_flags(char s, va_list arg)
{
	int c_count;

	c_count = 0;
	if (s == 's')
		c_count += ft_putstr(va_arg(arg, char *));
	if (s == 'd')
		c_count += ft_putnbr(va_arg(arg, int));
	if (s == 'x')
		c_count += ft_puthex(va_arg(arg, unsigned), c_count);
	return (c_count);
}

int	ft_printf(const char *orig, ...)
{
	va_list arg;
	char *str;
	int	c_count;

	c_count = 0;
	va_start(arg, orig);
	str = (char *)orig;
	while(*str)
	{
		if (*str == '%')
		{
			str++;
			c_count += check_flags(*str, arg);
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
