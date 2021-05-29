/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:18:04 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/26 18:20:37 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	while (n--)
	{
		if (*s1 != *s2)
		{
			if ((*s1 - *s2) < 0)
				return (-1);
			if ((*s1 - *s2) > 0)
				return (1);
		}
		s1++;
		s2++;
	}
	return (0);
}
