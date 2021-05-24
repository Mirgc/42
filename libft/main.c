#include <stdio.h>
#include <string.h>
#include "ft_strlen.c"
#include "ft_memset.c"
#include "ft_bzero.c"

int main ()
{
	char *str = "Hola que tal";
	char str2[50] = "This is string.h library function";
	char str3[50] = "This is string.h library function";
	char str4[50] = "This is string.h library function";
    char str5[50] = "This is string.h library function";

	printf ("-----------------\n");
	printf("Original strlen= %lu\n", strlen(str));
	printf("-----Mio strlen= %lu\n", ft_strlen(str));

	printf ("-----------------\n");
	memset(str2,'$',7);
	printf("Original memset= %s\n", str2);
	ft_memset(str3, '$', 7);
	printf("-----Mio memset= %s\n", str3);

    printf ("-----------------\n");
    bzero(str4, 5);
	printf("lalal = %s\n", str4);
	printf("Original bzero= ");
	int i = 0;
	while (i < 50)
	{
	    printf("%c", str4[i]);
		i++;
	}
	printf ("\n");
	ft_bzero(str5, 5);
	printf("-----Mio bzero= ");
    int j = -1;
    while (++j != 50)
        printf("%c", str5[j]);
    printf ("\n");
}
