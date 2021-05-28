#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_isalnum.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include "ft_toupper.c"
#include "ft_tolower.c"
#include "ft_calloc.c"

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
	printf("Mi ft_idigit - %c - Value1 returned: %i\n", var1, ft_isdigit(var1));
	printf("Origi idigit - %c - Value2 returned: %i\n", var2, isdigit(var2));
	printf("Mi ft_idigit - %c - Value2 returned: %i\n", var2, ft_isdigit(var2));
	printf("Origi idigit - %c - Value3 returned: %i\n", var3, isdigit(var3));
	printf("Mi ft_idigit - %c - Value3 returned: %i\n", var3, ft_isdigit(var3));

	// isalnum
        printf ("-----------------\n");
        printf("Origi isalnum - %c - Value1 returned: %i\n", var1, isalnum(var1));
        printf("Mi ft_isalnum - %c - Value1 returned: %i\n", var1, ft_isalnum(var1));
        printf("Origi isalnum - %c - Value2 returned: %i\n", var2, isalnum(var2));
        printf("Mi ft_isalnum - %c - Value2 returned: %i\n", var2, ft_isalnum(var2));
        printf("Origi isalnum - %c - Value3 returned: %i\n", var3, isalnum(var3));
        printf("Mi ft_isalnum - %c - Value3 returned: %i\n", var3, ft_isalnum(var3));
        printf("Origi isalnum - %c - Value4 returned: %i\n", var4, isalnum(var4));
        printf("Mi ft_isalnum - %c - Value4 returned: %i\n", var4, ft_isalnum(var4));

	// isascii
        printf ("-----------------\n");
        printf("Origi isascii - %c - Value1 returned: %i\n", var1, isascii(var1));
        printf("Mi ft_isascii - %c - Value1 returned: %i\n", var1, ft_isascii(var1));
        printf("Origi isascii - %c - Value2 returned: %i\n", var2, isascii(var2));
        printf("Mi ft_isascii - %c - Value2 returned: %i\n", var2, ft_isascii(var2));
        printf("Origi isascii - %c - Value3 returned: %i\n", var3, isascii(var3));
        printf("Mi ft_isascii - %c - Value3 returned: %i\n", var3, ft_isascii(var3));
        printf("Origi isascii - %c - Value4 returned: %i\n", var4, isascii(var4));
        printf("Mi ft_isascii - %c - Value4 returned: %i\n", var4, ft_isascii(var4));

	// isprint
        printf ("-----------------\n");
	char cadena[] = ";0 ñ\003sáR(h &~?\177RÛ 1/";
	int i;
   	
	i = 0;
	printf("Origi isprint :");
	while(cadena[i]) 
	{
		printf("%d-", isprint(cadena[i]));
		i++;
	}
        printf ("\n");
	i = 0;
	printf("Mi ft_isprint :");
	while(cadena[i]) 
	{
		printf("%d-", ft_isprint(cadena[i]));
		i++;
	}
        printf ("\n");

	// toupper
	printf ("-----------------\n");
        printf("Origi toupper - %c - Value1 returned: %c\n", var1, toupper(var1));
        printf("Mi ft_toupper - %c - Value1 returned: %c\n", var1, ft_toupper(var1));
        printf("Origi toupper - %c - Value2 returned: %c\n", var2, toupper(var2));
        printf("Mi ft_toupper - %c - Value2 returned: %c\n", var2, ft_toupper(var2));
        printf("Origi toupper - %c - Value3 returned: %c\n", var3, toupper(var3));
        printf("Mi ft_toupper - %c - Value3 returned: %c\n", var3, ft_toupper(var3));

	// tolower
        printf ("-----------------\n");
        printf("Origi tolower - %c - Value1 returned: %c\n", var1, tolower(var1));
        printf("Mi ft_tolower - %c - Value1 returned: %c\n", var1, ft_tolower(var1));
        printf("Origi tolower - %c - Value2 returned: %c\n", var2, tolower(var2));
        printf("Mi ft_tolower - %c - Value2 returned: %c\n", var2, ft_tolower(var2));
        printf("Origi tolower - %c - Value3 returned: %c\n", var3, tolower(var3));
        printf("Mi ft_tolower - %c - Value3 returned: %c\n", var3, ft_tolower(var3));

	// calloc
	printf ("-----------------\n");
	int j;
	int *a, *b;

	a = (int*)calloc(10, sizeof(int));
	printf("Origi calloc numbers: ");
	j = 0;
	while (j < 10) {
		printf("%d ",a[j]);
		j++;
	}
	printf("\n");
	b = ft_calloc(10, sizeof(int));
	printf("My ft_calloc numbers: ");
        j = 0;
        while (j < 10) {
                printf("%d ",a[j]);
                j++;
        }
	printf("\n");
	free (a);
	return (0);
}
