#include <stdio.h>
int ft_printf(const char *s, ...);
int main()
{
        char prueba[]= "Primera";
		char pp[100000];
		(void)pp;
		char p[]= "lalalalalalalalala";
		int x = 12111;
		int z = -1111111;
		int i = +2147483647;
		unsigned int j = 4294967286;

        ft_printf("Mi caracter '%c', '%c'\n", prueba[1], prueba[2]);
        printf("pr caracter '%c', '%c'\n\n", prueba[1], prueba[2]);
        ft_printf("Mi string '%s'\n", prueba);
        printf("pr string '%s'\n\n", prueba);
        ft_printf("Mi puntero '%p'\n", &p);
        printf("pr puntero '%p'\n\n", &p);
        ft_printf("Mi decimal '%d'\n", x);
        printf("pr decimal '%d'\n\n", x);
        ft_printf("Mi entero '%i'\n", i);
        printf("pr entero '%i'\n\n", i);
        ft_printf("Mi unsigned decimal '%u'\n", j);
        printf("pr unsigned decimal '%u'\n\n", j);
        ft_printf("Mi hexaminus '%x'\n", z);
        printf("pr hexaminus '%x'\n\n", z);
        ft_printf("Mi hexamayus '%X'\n", x);
        printf("pr hexamayus '%X'\n\n", x);
        ft_printf("Mi porciento '%%'\n");
        ft_printf("pr porciento '%%'\n\n");
}
