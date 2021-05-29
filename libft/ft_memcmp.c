/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:15:27 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/25 18:41:48 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*st1;
	char	*st2;
	int		i;

	st1 = (char *)s1;
	st2 = (char *)s2;
	i = 1;
	while (n--)
	{
		if (st1 != st2)
			return (*st1 - *st2);
	}
	return (0);
}
