#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
//#include "ex05/ft_atoi_base.c"


int main()
{
	int n, a;;

//	char dest[30] = "hola buenas";
	char str[50] = "1234";
//	char str2[30] = "0123456789";
//	char dest[4];
//	char pru[30];
//	int tab[7] = {3434,545,232,4343,34335,234,0};

	n = 0;
	a = 21;

/*	n = strlen(str);
	printf("Tiene que salir: %i\n",n);
	printf("Sale: %i", ft_strlen(str));*/

//	ft_putstr(str);

//	ft_putnbr(-2147483647);

//	printf("Sale: %d", ft_atoi(str));

	ft_putnbr_base(a, str);

//	printf("Sale: %d", ft_atoi_base(str, str2));

	return 0;	
}

