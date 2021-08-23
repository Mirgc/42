/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:03:50 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/19 16:54:38 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H  
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct s_list{
	long		num;
	int		ite;
	struct s_list	*next;
}	t_list;

void	sa_sb(t_list **arr);
void	pa_pb(t_list **arr_from, t_list **arr_to);
void	ra_rb(t_list **arr);
void	rra_rrb(t_list **arr);
void    op_1(t_list **arr);
void    op_2(t_list **arr);
void    op_3(t_list **arr);
void    op_4(t_list **arr);
void    op_5(t_list **arr);
void    op_6(t_list **arr);
void    op_7(t_list **arr);
void    op_8(t_list **arr);
void    op_9(t_list **arr);
int      arr_rot(t_list **arr, int rot);
int      arr_push(t_list **arr_a, t_list **arr_b, int half);
void    arr_push_back(t_list **arr_a, t_list **arr_b, int half);
void    rotate_rot(t_list **arr, int back);
void    swap_three_b3(t_list **arr);
void    swap_three_b2(t_list **arr);
void    swap_three_b(t_list **arr);
void    swap_three(t_list **arr);
void    swap_two(t_list **arr);
void    swap_arr(t_list **arr_a, t_list **arr_b, int *change, int len);
int     get_mid(t_list *arr, int len);
void    sort_array(long *array);
void    quick_sort(long *stack1, int start, int end);
int	div_arr_a(t_list **arr_a, t_list **arr_b, int len);
int	div_arr_b(t_list **arr_a, t_list **arr_b, int len);
int     is_sorted(t_list **arr, int len);
t_list  *ft_lstnew(long content);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void	ft_swap(long *a, long *b);
void	ft_printerr();
void	ft_putstr(char *str);
int	ft_arr_len(t_list **arr);
size_t  ft_strlen(char **s);
long	ft_atoi(char *str);
char    **ft_split(char const *s, char c);
void	del_node(t_list **arr);
t_list	*add_node(void);
long	isisnum(char *str);
long	is_num(char *str, t_list **f_arr);
t_list	*fill_arra(int argc, char **argv);
# endif
