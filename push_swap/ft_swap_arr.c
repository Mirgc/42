
#include "push_swap.h"

static int	create_len_a(t_list **arr, int change, int len)
{
	int	s_len;

	change = change;
	if ((*arr)->ite == 1)
	{
		change = 1;
		s_len = len -len / 2;
	}
	else
		s_len = len / 2;
	return (s_len);
}

static int	create_len_b(t_list **arr, int change, int len)
{
	int	s_len;

	change = change;
	if ((*arr)->ite == 1)
	{
		change = 1;
		s_len = len / 2;
	}
	else
		s_len = len - len / 2;
	return (s_len);
}

static void	swap_len_two(t_list **arr_a, t_list **arr_b, int change, int len)
{
	int	len_1;
	int	len_2;

	len_1 = create_len_a(arr_a, change, len);
	len_2 = create_len_b(arr_a, change, len);
	if (len_1 == 2 && (!(*arr_a) || ft_arr_len(arr_a) < 2))
		return ;
	else if (len_1 == 2 && (!(*arr_b) || ft_arr_len(arr_b) < 2 || len_2 > 3))
		swap_two(arr_a);
	else if (len_1 == 2 && len_2 == 2)
	{
		swap_two(arr_a);
		swap_two(arr_b);
	}
	else if (len_1 == 2 && len_2 == 3 && ft_arr_len(arr_b) > 2)
	{
		swap_two(arr_a);
		swap_three(arr_b);
	}
}

static void	swap_len_three(t_list **arr_a, t_list **arr_b, int change, int len)
{
	int	len_1;
	int	len_2;

	len_1 = create_len_a(arr_a, change, len);
	len_2 = create_len_b(arr_a, change, len);
	if (len_1 > 3 && len_2 == 2)
		swap_two(arr_b);
	else if (len_1 == 3 && (!(*arr_a) || ft_arr_len(arr_a) < 3))
		return ;
	else if (len_1 == 3 && (!(*arr_b) || ft_arr_len(arr_b) < 2 || len_2 > 3))
		swap_three(arr_a);
	else if (len_1 == 3 && len_2 == 2)
	{
		swap_three(arr_a);
		swap_two(arr_b);
	}
	else if (len_1 == 3 && len_2 == 3 && ft_arr_len(arr_b) > 2)
	{
		swap_three(arr_a);
		swap_three(arr_b);
	}
	else if (len_1 > 3 && len_2 == 3)
		swap_three(arr_b);
}

void	swap_arr(t_list **arr_a, t_list **arr_b, int change, int len)
{
	int		len_1;

	len_1 = create_len_a(arr_a, change, len);
	if (len_1 == 2)
		swap_len_two(arr_a, arr_b, change, len);
	else if (len_1 > 2)
		swap_len_three(arr_a, arr_b, change, len);
}
