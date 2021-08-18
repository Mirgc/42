#include "push_swap.h"

void	op_6(t_list **arr)
{
	rra_rrb(arr);
	sa_sb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("rra\nsa\n");
	else
		ft_putstr("rrb\nsb\n");
}

void	op_7(t_list **arr)
{
	ra_rb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("ra\n");
	else
		ft_putstr("rb\n");
}

void	op_8(t_list **arr)
{
	rra_rrb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("rra\n");
	else
		ft_putstr("rrb\n");
}

void	op_9(t_list **arr)
{
	ra_rb(arr);
	sa_sb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("ra\nsa\n");
	else
		ft_putstr("rb\nsb\n");
}
