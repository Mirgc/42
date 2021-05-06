#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ex00/ft_strdup.c"

int main()
{
	char str[]={"Hola buenas"};

	printf("%s\n", strdup(str));
	printf("%s\n", ft_strdup(str));

	return 0;
}
