
#include "push_swap.h"

void	op_1(t_list **arr)
{
	sa_sb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("sa\n");
	else
		ft_putstr("sb\n");
}

void	op_2(t_list **arr)
{
	ra_rb(arr);
	sa_sb(arr);
	rra_rrb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("ra\nsa\nrra\n");
	else
		ft_putstr("rb\nsb\nrrb\n");
}

void	op_3(t_list **arr)
{
	sa_sb(arr);
	ra_rb(arr);
	sa_sb(arr);
	rra_rrb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("sa\nra\nsa\nrra\n");
	else
		ft_putstr("sb\nrb\nsb\nrrb\n");
}

void	op_4(t_list **arr)
{
	ra_rb(arr);
	sa_sb(arr);
	rra_rrb(arr);
	sa_sb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("ra\nsa\nrra\nsa\n");
	else
		ft_putstr("rb\nsb\nrrb\nsb\n");
}

void	op_5(t_list **arr)
{
	sa_sb(arr);
	ra_rb(arr);
	sa_sb(arr);
	rra_rrb(arr);
	sa_sb(arr);
	if ((*arr)->ite == 1)
		ft_putstr("sa\nra\nsa\nrra\nsa\n");
	else
		ft_putstr("sb\nrb\nsb\nrrb\nsb\n");
}
