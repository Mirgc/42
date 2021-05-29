#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ft_substr.c"
#include "ft_strjoin.c"
#include "ft_strtrim.c"
#include "ft_split.c"
#include "ft_itoa.c"

int main ()
{
	// substr
	printf ("-----------------\n");
	char source[] = "0123456789";
    char *target = ft_substr(source, 4, 10); 

	printf("My ft_substr: %s\n", target);
	
	// strjoin 
	printf ("-----------------\n");
	char s1[]="lalala";
	char s2[]="tiririporopopo";
	char *dst;

	dst = ft_strjoin(s1, s2);
	printf("My ft_strjoin: %s\n", dst);

	// strtrim
	printf ("-----------------\n");
	char s3[]="hola no sale hola";
	char *dst2;

	dst2 = ft_strtrim(s3, "hola");
	printf("My ft_strtrim: %s\n", dst2);

	// split
	printf ("-----------------\n");
	char s4[]= "Tengo todo a la hora de comer";
	char **tab;
	int i;

	tab = ft_split(s4, 'a');
	i = 0;
	printf("String a cortar: '%s'\n",s4);
	while (tab[i])
	{
		printf("linea %i - %s\n", i, tab[i]);
		i++;
	}

	// ft_itoa
	printf ("-----------------\n");
	char *nbr;
	
	nbr = ft_itoa(-1234);
	printf("My ft_itoa: '%s'", nbr);
	return (0);
}
