/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:49:17 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/02 21:41:09 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFSIZE 128
# define DICT_NAME "numbers.dict"

typedef struct s_list
{
	int		nb;
	char	*str;
}	t_list;

struct	s_list	*ft_parse(char *dictionary);
struct	s_list	*ft_read_dict_file(char *dict_name);
int				write_number(unsigned int number, t_list *tab);

#endif
