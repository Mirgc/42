#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcpy.c"
#include "ex01/ft_strncpy.c"
#include "ex02/ft_str_is_alpha.c"
#include "ex03/ft_str_is_numeric.c"
#include "ex04/ft_str_is_lowercase.c"
#include "ex05/ft_str_is_uppercase.c"
#include "ex06/ft_str_is_printable.c"
#include "ex07/ft_strupcase.c"
#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
#include "ex10/ft_strlcpy.c"
#include "ex11/ft_putstr_non_printable.c"
//#include "ex12/ft_print_memory.c"


int main()
{
//	int n, a, i;//, b, div, mov, longitud, len;
	char str[] = "3ñ.";
//	char dest[50] = "";
//	char pru[50] = "";
//	int tab[7] = {3434,545,232,4343,34335,234,0};

//	n = 8;
//	a = 8;

/*	printf("Texto origen: %s.\n", str);
	ft_strcpy(dest,str);
	printf("Mi funcion: %s.\n", dest);
	strcpy(pru,str);
	printf("Strcpy: %s.\n", pru);*/
	
/*	printf("Texto origen: %s.\n", str);
    ft_strncpy(dest, str, n);
    printf("Mi funcion: %s.\n", dest);
    strncpy(pru,str, n);
    printf("Strcnpy: %s.\n", pru);*/

//	printf("%i.", ft_str_is_alpha(str));
//	printf("%i.", ft_str_is_numeric(str));
//	printf ("%i.", ft_str_is_lowercase(str));
//	printf ("%i.", ft_str_is_uppercase(str));
//	printf ("%i.", ft_str_is_printable(str));
//	printf ("%s \n", str);
//	ft_strupcase(str);
//	ft_strlowcase(str);
//	ft_strcapitalize(str);
//	printf ("%s", str);

/*	i=ft_strlcpy(dest, str, n);
	printf ("Mi funcion: %i\n", i);
    a=strlcpy(pru ,str, n);
    printf("Strclpy: %i\n", a);*/

	ft_putstr_non_printable(str);	
//	ft_print_memory(str, n);
//printf ("%s", str);
	return 0;	
}

