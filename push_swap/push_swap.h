/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:03:50 by migarcia          #+#    #+#             */
/*   Updated: 2021/08/03 20:25:09 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H  
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list{
	long		num;
	int		ite;
	struct s_list	*next;
}	t_list;

typedef struct	s_res
{
	int	chang;
	char	*result;
}	t_res;

void	sa_sb(t_list **arr);
void	pa_pb(t_list **arr_from, t_list **arr_to);
void	ra_rb(t_list **arr, char *ope);
void	rra_rrb(t_list **arr);
int     is_sorted(t_list *arr_a, int len);
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
void    push_swap(t_list **arr_a, t_list **arr_b);
# endif
