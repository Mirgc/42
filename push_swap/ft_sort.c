
#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_list *arr_a, int len)
{

	if (len == 0)
		return (1);
	while (arr_a->next != NULL)
	{
		if (arr_a->num > arr_a->next->num)
			return (0);
		arr_a = arr_a->next;
	}
	return (1);
}
