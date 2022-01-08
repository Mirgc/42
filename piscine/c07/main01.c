#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "ex01/ft_range.c"

int main()
{
	int *arr;
	int	min;
	int	max;
	int	i;

	i = 0;
	min = 39;
	max = 60;
	arr = ft_range(min, max);
	while (i < max - min)
	{
		printf("%i, ", arr[i]);
		i++;
	}

	return 0;
}
