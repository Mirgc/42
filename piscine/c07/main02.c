#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ex02/ft_ultimate_range.c"

int main()
{
	int *arr;
	int	min;
	int	max;
	int	i;
	int	size;

	i = 0;
	min = 10;
	max = 620;
	size = ft_ultimate_range(&arr, min, max);
	printf("%i \n", size);
	while (i < max - min)
	{
		printf("%i, ", arr[i]);
		i++;
	}

	return 0;
}
