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

t_list  *ft_lstnew(long content);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void	ft_printerr();
size_t  ft_strlen(char **s);
long	ft_atoi(char *str);
char    **ft_split(char const *s, char c);
void	del_node(t_list **arr);
t_list	*add_node(void);
long isisnum(char *str);
long		is_num(char *str, t_list **f_arr);
t_list	*fill_arra(int argc, char **argv);
# endif
