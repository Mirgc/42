#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"


int main()
{
	int n, a;//, i;//, b, div, mov, longitud, len;

//	char dest[30] = "hola buenas";
	char str[50] = "hola buenas";
	char str2[30] = "hola";
//	char dest[4];
//	char pru[30];
//	int tab[7] = {3434,545,232,4343,34335,234,0};

	n = 0;
	a = 25;

	n = strcmp(str, str2);
	printf("Tiene que salir: %i\n",n);
	printf("Sale: %i", ft_strcmp(str, str2));

/*	n = strncmp(str, str2, a);
    printf("Tiene que salir: %i\n",n);
    printf("Sale: %i", ft_strncmp(str, str2, a));*/

/*  printf("Tiene que salir: %s\n", strcat(dest, str2));
    printf("Sale: %s", ft_strcat(str, str2));*/

/*  printf("Tiene que salir: %s\n", strncat(dest, str2, a));
    printf("Sale: %s", ft_strncat(str, str2, a));*/

/*  printf("Tiene que salir: %s\n", strstr(dest, str2));
	printf("Sale: %s", ft_strstr(str, str2));*/

//	printf("Tiene que salir: %lu\n", strlcat(str, str2, a));
//    printf("Sale: %u", ft_strlcat(str, str2, a));

	return 0;	
}

