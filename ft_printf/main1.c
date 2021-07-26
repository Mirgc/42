#include <stdio.h>
int ft_printf(const char *s, ...);
int main()
{
        char prueba[]= "Primera";
        ft_printf("Hola esto es un caracter '%c', '%c'\n", prueba[1], prueba[2]);
        ft_printf("Hola esto es un string '%s'\n", prueba);
        ft_printf("Hola esto es un puntero '%p'\n", prueba);
        printf("Hola esto es un caracter %c\n", prueba[1]);
}
