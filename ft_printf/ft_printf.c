#include <stdarg.h>
#include <unistd.h>

void check_flag(char *s, char *str)
{

}

int ft_printf(const char *orig, ...)
{
	va_list arg;
	char	*s;
	char	*str;
	va_start(arg, orig);

	s = (char *)orig;
	str = va_arg(arg, char *);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			check_flag(s, str);
		}
		write (0, s, 1);
		s++;
	}
	return (0);
}
