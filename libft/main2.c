#include <stdio.h>
#include <string.h>
#include "ft_strlcat.c"
#include "ft_strchr.c"
#include "ft_strrchr.c"
#include "ft_strnstr.c"
#include "ft_strncmp.c"
#include "ft_atoi.c"

int main ()
{
	//strlcat
	printf ("-----------------\n");
	char first[20] = "This is pepe";
	char first2[20] = "This is pepe";
	char last[] = "a potentially long strin";
	int r;

	r = strlcat(first, last, 10);
	printf("Origi strlcat - %s - Value returned: %d\n", first, r);
	r = ft_strlcat(first2, last, 10);
	printf("Mi ft_strlcat - %s - Value returned: %d\n", first2, r);


	// strchr
	printf ("-----------------\n");
	char str[] = "This is a sample string";

	printf ("Looking for the 's' character in \"%s\"...\n",str);
	printf ("Original strchr found -%s-\n", strchr(str,'s'));
	printf ("---My ft_strchr found -%s-\n", ft_strchr(str,'s'));


	// strchr
	printf ("-----------------\n");
	printf ("Looking for the last 's' character in \"%s\"...\n",str);
	printf ("Original strrchr found -%s-\n", strrchr(str,'u'));
	printf ("---My ft_strrchr found -%s-\n", ft_strrchr(str,'u'));

	// strnstr
	printf ("-----------------\n");
	printf ("Looking for the last 's' character in \"%s\"...\n",str);
	printf ("---My ft_strnstr found -%s-\n", ft_strnstr(str,"e",16));

	// strncmp
	printf ("-----------------\n");
	printf ("Original strncmp = %i\n", strncmp("Esto es una prueba", "Esto es una prueba", 7));
	printf ("---My ft_strncmp = %i\n", ft_strncmp("Esto es una prueba", "Esto es una prueba", 7));

	// atoi
	printf ("-----------------\n");
	printf ("Original atoi =%i\n", atoi("  123!")); 
	printf ("---My ft_atoi =%i\n", ft_atoi("  123!")); 
	return (0);
}
