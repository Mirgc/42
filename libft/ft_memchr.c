/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:55:27 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/25 18:09:06 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (n-- && *s)
	{
		if (s[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
