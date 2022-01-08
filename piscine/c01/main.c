#include <stdio.h>
#include <string.h>
//#include "ex02/ft_swap.c"
//#include "ex03/ft_div_mod.c"
//#include "./ex04/ft_ultimate_div_mod.c"
//#include "ex05/ft_putstr.c"
//#include "ex06/ft_strlen.c"
//#include "ex07/ft_rev_int_tab.c"
#include "ex08/ft_sort_int_tab.c"


int main()
{
	int i, a, b, div, mov;//, longitud, len;
	//char str[] = "Hola";
	int tab[7] = {3434,545,232,4343,34335,234,0};

	i = 0;
	a = 10;
	b = 7;
	div = 0;
	mov = 0;
/*	printf("%i, %i", a, b);
	ft_swap(&a, &b);
	printf("%i, %i",a, b);*/

/*	ft_div_mod(a, b , &div, &mov);
	printf("%i, %i",div, mov);*/

/*	ft_ultimate_div_mod( &a, &b);
	printf("%i, %i",a, b);*/

	//ft_putstr(str);
	
/*	longitud = ft_strlen(str);
	len = strlen(str);
	printf("%i, %i",longitud, len);*/

	ft_sort_int_tab(tab, b);
	while (i != 7)
	{
		printf("%i, ",tab[i]);
		i++;
	}
	return 0;	
}

