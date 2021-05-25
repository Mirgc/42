#include <stdio.h>
#include <string.h>
#include "ft_strlen.c"
#include "ft_memset.c"
#include "ft_bzero.c"
#include "ft_memcpy.c"
#include "ft_memccpy.c"
#include "ft_memmove.c"
#include "ft_memchr.c"

int main ()
{
	char *str = "Hola que tal";
	char str2[50] = "This is string.h library function";
	char str3[50] = "This is string.h library function";
	char str4[50] = "This is string.h library function";
	char str5[50] = "This is string.h library function";

	// strlen
	printf ("-----------------\n");
	printf("Original strlen= %i\n", strlen(str));
	printf("-----Mio strlen= %i\n", ft_strlen(str));

	// memset
	printf ("-----------------\n");
	memset(str2,'$',7);
	printf("Original memset= %s\n", str2);
	ft_memset(str3, '$', 7);
	printf("-----Mio memset= %s\n", str3);

	// bzero
	printf ("-----------------\n");
	bzero(str4, 5);
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
	
	// memcpy
	printf ("-----------------\n");
	const char src[50] = "Hola que tal";
	char dest[5] = "HOL";
	const char src2[50] = "Hola que tal";
	char dest2[5] = "HOL";

        printf("Antes memcpy dest = %s\n", dest);
	memcpy(dest, src, 12);
	printf("Despu memcpy dest = %s\n", dest);

	printf("Antes ft_memcpy dest = %s\n", dest2);
	ft_memcpy(dest2, src2, 12);
	printf("Despu ft_memcpy dest = %s\n", dest2);

	// memccpy
	printf ("-----------------\n");
	char msg[80] = "This is the string: not copied";
	char buffer[80];
	char* msg2 = "This is the string: not copied";
	char buffer2[80];

        memset(buffer, '\0', 80);
	memccpy(buffer, msg, ':', 80);
        printf("Original memccpy= %s\n", buffer);
	ft_memccpy(buffer2, msg2, ':', 80);
	printf("-----Mio memccpy= %s\n", buffer2);

	// memmove
	printf ("-----------------\n");
	char dest3[] = "oldstring";
	char src3[]  = "new";
	char dest4[] = "oldstring";
	char src4[]  = "new";

	printf("Antes memmove dest = %s, src = %s\n", dest3, src3);
	memmove(dest3, src3, 4);
	printf("Despu memmove dest = %s, src = %s\n", dest3, src3);
	printf("Antes ft_memmove dest = %s, src = %s\n", dest4, src4);
	ft_memmove(dest4, src4, 4);
	printf("Despu ft_memmove dest = %s, src = %s\n", dest4, src4);

	// memchr
	printf ("-----------------\n");
	const char str6[] = "Aqui si que hay un . punto";
	const char str7[] = "Aqui si que hay un . punto";
	const char ch = '.';
	char* punt;
	char* punt2;
	
	punt = memchr(str6, ch, 4);
	printf("lib memchr: ch-|%c| String-|%s|\n", ch, punt);
	punt2 = memchr(str7, ch, 4);
	printf(" ft_memchr: ch-|%c| String-|%s|\n", ch, punt2);

	// memcmp
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";

	int n;

	n=memcmp ( buffer1, buffer2, sizeof(buffer1) );

	return (0);
}
