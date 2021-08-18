#include "push_swap.h"

int      arr_rot(t_list **arr, int rot)
{
        ra_rb(arr);
        if ((*arr)->ite == 1)
                ft_putstr("ra\n");
        else
                ft_putstr("rb\n");
        rot++;
        return (rot);
}

int	arr_push(t_list **arr_a, t_list **arr_b, int half)
{
	if ((*arr_a)->ite == 1)
		(*arr_a)->ite = 2;
        pa_pb(arr_a, arr_b);
        if ((*arr_a)->ite == 1)
                ft_putstr("pb\n");
        else
                ft_putstr("pa\n");
        half--;
        return (half);
}

void    rotate_rot(t_list **arr, int back)
{
	int	 len;

	len = ft_arr_len(arr);
        if (len == 2)
        {
                swap_two(arr);
                return ;
        }
        if (len == 3)
        {
                swap_three(arr);
                return ;
        }
        while (back != 0)
        {
                rra_rrb(arr);
                if ((*arr)->ite == 1)
                        ft_putstr("rra\n");
                else
                        ft_putstr("rrb\n");
                back--;
        }
}


int	div_stack_a(t_list **arr_a, t_list **arr_b, int len)
{
        int             rot;
        int             mid;
        t_list		*tmp;
        int             half;

        half = len / 2;
        tmp = *arr_a;
        rot = 0;
        mid = get_mid(*arr_a, len);
        while (tmp && half >= 0)
        {
                if (((*arr_a)->ite == 1 && tmp->num < mid) ||
                        ((*arr_a)->ite == 2 && tmp->num <= mid))
                {
                        while ((*arr_a)->num != tmp->num)
                                rot = arr_rot(arr_a, rot);
                        tmp = tmp->next;
                        half = arr_push(arr_a, arr_b, half);
                }
                else
                        tmp = tmp->next;
        }
        return (rot);
}

int	div_stack_b(t_list **arr_a, t_list **arr_b, int len)
{
        int     rot;
        int     mid;
        t_list	*tmp;
        int     half;

        half = len - len / 2;
        tmp = *arr_a;
        rot = 0;
        mid = get_mid(*arr_a, len);
        while (tmp && half > 0)
        {
                if (((*arr_a)->ite == 1 && tmp->num > mid) ||
                        ((*arr_a)->ite == 2 && tmp->num >= mid))
                {
                        while ((*arr_a)->num != tmp->num)
                                rot = arr_rot(arr_a, rot);
                        tmp = tmp->next;
                        half = arr_push(arr_a, arr_b, half);
                }
                else
                        tmp = tmp->next;
        }
        return (rot);
}

