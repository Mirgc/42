#include <stdio.h>
#include <string.h>
#include "libft.h"
//#include "ft_strlen.c"
//#include "ft_memset.c"
//#include "ft_bzero.c"
//#include "ft_memcpy.c"
//#include "ft_memccpy.c"
//#include "ft_memmove.c"
//#include "ft_memchr.c"
//#include "ft_memcmp.c"
//#include "ft_strlcpy.c"

int main ()
{
	char *str = "Hola que tal";
	char str2[50] = "This is string.h library function";
	char str3[50] = "This is string.h library function";
	char str4[50] = "This is string.h library function";
	char str5[50] = "This is string.h library function";

	// strlen
	printf ("-----------------\n");
	printf ("-----------------\n");
	printf("Original strlen= %lu\n", strlen(str));
	printf("-----Mio strlen= %lu\n", ft_strlen(str));

	// memset
	printf ("-----------------\n");
	printf ("-----------------\n");
	memset(str2,'$',7);
	printf("Original memset= %s\n", str2);
	ft_memset(str3, '$', 7);
	printf("-----Mio memset= %s\n", str3);

	// bzero
	printf ("-----------------\n");
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
	printf ("-----------------\n");
	const char src[50] = "Hola que tal";
	char dest[5] = "HOL";
	const char src2[50] = "Hola que tal";
	char dest2[5] = "HOL";

	printf("Antes memcpy dest = %s\n", dest);
	memcpy(dest, src, 5);
	printf("Despu memcpy dest = %s\n", dest);

	printf("Antes ft_memcpy dest = %s\n", dest2);
	ft_memcpy(dest2, src2, 5);
	printf("Despu ft_memcpy dest = %s\n", dest2);

	// memccpy
	printf ("-----------------\n");
	printf ("-----------------\n");
	char msg[80] = "zyxwvutsrqponmlkjihgfedcba";
	char buffer[80];
	char* msg2 = "zyxwvutsrqponmlkjihgfedcba";
	char buffer2[80];

	memset(buffer, '\0', 80);
	memccpy(buffer, msg, 'r', 20);
	printf("Original memccpy= %s\n", buffer);
	ft_memccpy(buffer2, msg2, 'r', 20);
	printf("-----Mio memccpy= %s\n", buffer2);

	// memmove
	printf ("-----------------\n");
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
	printf ("-----------------\n");
	printf ("-----------------\n");
	char buffer3[] = "abcdefghij";
	char buffer4[] = "abcdefgxyz";

	int n;
	int m;

	n=memcmp(buffer3, buffer4, 7);
	printf("Original memcmp sale = %i\n", n);
	m=ft_memcmp(buffer3, buffer4, 7);
	printf("---Mio ft_memcmp sale = %i\n", n);
	
	// strlcpy
	/*printf ("-----------------\n");
	printf ("-----------------\n");
	char dst5[20] ="";
	char dst6[20] ="";
	char str8[] = "Aqui si que hay un . punto";

	printf("Original strlcpy - Longitud %lu, string '%s'\n", strlcpy(dst5, str8, 10), dst5);
	printf("--Mio ft_strlcpy - Longitud %lu, string '%s'\n", ft_strlcpy(dst6, str8, 10), dst6);*/
	return (0);
}
