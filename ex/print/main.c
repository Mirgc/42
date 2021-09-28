#include <stdio.h>

int	ft_printf(const char *orig, ...);

int	main()
{
	printf("(%i)\n", printf("1: Hola %s\n", "toto"));
	printf("(%i)\n", ft_printf("2: Hola %s\n", "toto"));
	printf("(%i)\n", printf("1: El numero magico es %d\n", 42));
	printf("(%i)\n", ft_printf("2: El numero magico es %d\n", 42));
	printf("(%i)\n", printf("1: %d, %d, %d, %d, %d\n", -42, 15, 2147483647, -2147483647, -0));
	printf("(%i)\n", ft_printf("2: %d, %d, %d, %d, %d\n", -42, 15, 2147483647, -2147483647, -0));
	printf("(%i)\n", printf("1: %s, %s, %s, %s\n", NULL, "hol\0a", "mundo", "Lorem ipsum"));
	printf("(%i)\n", ft_printf("2: %s, %s, %s, %s\n", NULL, "hol\0a", "mundo", "Lorem ipsum"));
	printf("(%i)\n", printf("1: %x, %x, %x, %x, %x\n", -42, 14, 2147483647, -2147483647, -0));
	printf("(%i)\n", ft_printf("2: %x, %x, %x, %x, %x\n", -42, 14, 2147483647, -2147483647, -0));
}
