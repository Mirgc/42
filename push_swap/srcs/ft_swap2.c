#include "push_swap.h"

void    ft_swap(long *a, long *b)
{
        long tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

void    swap_three_b3(t_list **arr)
{
	if ((*arr)->num < (*arr)->next->num &&
                (*arr)->next->num < (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_5(arr);
                else
                        op_9(arr);
        }
}

void    swap_three_b2(t_list **arr)
{
	if ((*arr)->num < (*arr)->next->num &&
                (*arr)->next->num > (*arr)->next->next->num &&
                (*arr)->num < (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_3(arr);
                else
                        op_7(arr);
        }
        else if ((*arr)->num > (*arr)->next->num &&
                (*arr)->next->num < (*arr)->next->next->num &&
                (*arr)->num < (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_4(arr);
                else
                        op_8(arr);
        }
	else
		swap_three_b3(arr);
}

void    swap_three_b(t_list **arr)
{
	if ((*arr)->num > (*arr)->next->num &&
                (*arr)->next->num > (*arr)->next->next->num)
                return ;
        else if ((*arr)->num < (*arr)->next->num &&
                (*arr)->num > (*arr)->next->next->num &&
                (*arr)->next->num > (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_1(arr);
                else
                        swap_two(arr);
        }
        else if ((*arr)->num > (*arr)->next->num &&
                (*arr)->num > (*arr)->next->next->num &&
                (*arr)->next->num < (*arr)->next->next->num)
        {
                if (ft_arr_len(arr) > 3)
                        op_2(arr);
                else
                        op_6(arr);
        }
	else
		swap_three_b2(arr);
}
