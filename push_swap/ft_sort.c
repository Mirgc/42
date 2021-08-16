
#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_list **arr, int len)
{
	t_list	*tmp;

	tmp = *arr;
	if (len == 0)
		return (1);
	while (tmp->next != NULL)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	partition(long *array, int start, int end)
{
        int     end_val;
        int     strt_indx;
        int     curr_indx;

        end_val = array[end];
        strt_indx = start - 1;
        curr_indx = start;
        while (curr_indx <= end - 1)
        {
                if (array[curr_indx] <= end_val)
                {
                        strt_indx++;
                        ft_swap(&array[strt_indx], &array[curr_indx]);
                }
                curr_indx++;
        }
        ft_swap(&array[strt_indx + 1], &array[end]);
        return (strt_indx + 1);
}

void    quick_sort(long *array, int start, int end)
{
        long     temp[end + 1];
        int     top;
        int     pivot;

        top = -1;
        temp[++top] = start;
        temp[++top] = end;
        while (top >= 0)
        {
                end = temp[top--];
                start = temp[top--];
                pivot = partition(array, start, end);
                if (pivot - 1 > start)
                {
                        temp[++top] = start;
                        temp[++top] = pivot - 1;
                }
                if (pivot + 1 < end)
                {
                        temp[++top] = pivot + 1;
                        temp[++top] = end;
                }
        }
}

