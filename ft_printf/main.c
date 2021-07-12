#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void testit (int i, ...)
{
    va_list argptr;
    va_start(argptr, i);
	int j = 0;

    if (i == 0)
    {
        int n = va_arg(argptr, int);
        printf("%d\n", n);
    }
    else
    {
		while (j < i)
		{
        	char *s = va_arg(argptr, char*);
        	printf("%%%s\n", s);
			j++;
		}
    }

    va_end(argptr);
}

int main()
{
    testit(0, 0xFFFFFFFF); // 1st problem: 0xffffffff is not an int
    testit(1, NULL);       // 2nd problem: NULL is not a char*
	testit(2, "Hola", "Adios");
	return(0);
}
