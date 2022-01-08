#include "ex01/ft_strncpy.c"
#include <stdio.h>
int	main(void)
{
	char	texto[] = "Hello World";
	char	dest1[12];
	char	dest2[20];
	char	dest3[2];
	char	dest4[20];

	ft_strncpy(dest1, texto, 0);
	printf("%s \n", dest1);
	ft_strncpy(dest2, texto, 2);
	printf("%s \n", dest2);
	ft_strncpy(dest4, texto, 23);
	ft_strncpy(dest3, texto, 12);
	printf("%s \n", dest3);
	printf("Prueba overflow: Debe imprimir-> llo World\n");
	printf("%s \n", dest4);
}
