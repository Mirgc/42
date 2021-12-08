#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return(1);
}

int ft_putstr(char *str)
{
	int c_count;

	c_count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return(6);
	}
	while(*str)
	{
		c_count += ft_putchar(*str);
		str++;
	}
	return(c_count);
}

int ft_intlen(int num)
{
	int c_count;

	c_count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		c_count++;
	}
	return(c_count);
}

int ft_putnbr(long num)
{
	int c_count;

	c_count = 0;
	if (num < 0)
	{
		num *= -1;
		c_count += ft_putchar('-');
	}
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
		ft_putchar(num + '0');
	c_count += ft_intlen(num);
	return(c_count);
}

int ft_puthex(unsigned long num, int c_count)
{
	static int c_sta;
	int tmp;

	c_sta = 0;
	if (num == 0 && (c_count == 0 || c_count == 2))
		c_sta += ft_putchar('0');
	if (num != 0)
	{
		c_count = 1;
		ft_puthex(num / 16, c_count);
		tmp = num % 16;
		if (tmp > 9)
			c_sta += ft_putchar((tmp -10) + 'a');
		else
			c_sta += ft_putchar(tmp + '0');
	}
	return (c_sta);
}

int ft_checkflag(va_list arg, char c)
{
	int c_count;

	c_count = 0;
	if (c == 's')
		c_count += ft_putstr(va_arg(arg, char *));
	if (c == 'd')
		c_count += ft_putnbr(va_arg(arg, int));
	if (c == 'x')
		c_count += ft_puthex(va_arg(arg, unsigned), c_count);
	return(c_count);
}

int ft_printf(const char *format, ...)
{
	char *str;
	va_list arg;
	int c_count;

	c_count = 0;
	va_start(arg, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			c_count += ft_checkflag(arg, *str);
			str++;
		}
		else
		{
			c_count += ft_putchar(*str);
			str++;
		}
	}
	va_end(arg);
	return(c_count);
}
