/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:38:07 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:38:20 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		check_ch(char *str);
int		get_next_line(int fd, char **line);
int		ft_len(char *str);
char	*join(char *s1, char *s2);
char	*ft_dup(char *s1);
char	*ft_str(char *s, int start, size_t len);
#endif
