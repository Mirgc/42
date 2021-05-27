#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ft_isalpha.c"

int main ()
{
	// isalpha
	printf ("-----------------\n");
	int var1 = 'd';
	int var2 = 'Z';
	int var3 = '2';
	int var4 = '\t';
	int var5 = ' ';

	printf("Origi isalpha - %c - Value1 returned: %i\n", var1, isalpha(var1));
	printf("Mi ft_isalpha - %c - Value1 returned: %i\n", var1, ft_isalpha(var1));
	printf("Origi isalpha - %c - Value2 returned: %i\n", var2, isalpha(var2));
	printf("Mi ft_isalpha - %c - Value2 returned: %i\n", var2, ft_isalpha(var2));
	printf("Origi isalpha - %c - Value3 returned: %i\n", var3, isalpha(var3));
	printf("Mi ft_isalpha - %c - Value3 returned: %i\n", var3, ft_isalpha(var3));
	printf("Origi isalpha - %c - Value4 returned: %i\n", var4, isalpha(var4));
	printf("Mi ft_isalpha - %c - Value4 returned: %i\n", var4, ft_isalpha(var4));
	printf("Origi isalpha - %c - Value5 returned: %i\n", var5, isalpha(var5));
	printf("Mi ft_isalpha - %c - Value5 returned: %i\n", var5, ft_isalpha(var5));

	// isdigit
	printf ("-----------------\n");
    printf("Origi idigit - %c - Value1 returned: %i\n", var1, isdigit(var1));
	//printf("Mi ft_idigit - %c - Value1 returned: %i\n", var1, ft_isdigit(var1));
	printf("Origi idigit - %c - Value2 returned: %i\n", var2, isdigit(var2));
	//printf("Mi ft_idigit - %c - Value2 returned: %i\n", var2, ft_isdigit(var2));
	printf("Origi idigit - %c - Value3 returned: %i\n", var3, isdigit(var3));
	//printf("Mi ft_idigit - %c - Value3 returned: %i\n", var3, ft_isdigit(var3));

	return (0);
}
