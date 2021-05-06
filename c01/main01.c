#include "ex08/ft_sort_int_tab.c"
#include <stdio.h>

int main(void)
{
	printf("Inicio Test 08-> Función que Ordena numero\n");
	int i[5]={0,4,5,3,4};
	printf("Debe mostrar los caracteres -> 0,3,4,4,5\n");
	ft_sort_int_tab(i,5);
	printf("%d,%d,%d,%d,%d \n",i[0],i[1],i[2],i[3],i[4]);
	
	int b[5]={0,1,2,3,4};
    printf("Debe mostrar los caracteres -> 0,1,2,3,4\n");
    ft_sort_int_tab(b,5);
    printf("%d,%d,%d,%d,%d \n",b[0],b[1],b[2],b[3],b[4]);

	int c[7]={3434,545,232,4343,34335,234,0};
    printf("Debe mostrar los caracteres -> 0,232,234,545,3434,4343,34335\n");
    ft_sort_int_tab(c,7);
    printf("%d,%d,%d,%d,%d,%d,%d \n",c[0],c[1],c[2],c[3],c[4],c[5],c[6]);
	return(0);
}
