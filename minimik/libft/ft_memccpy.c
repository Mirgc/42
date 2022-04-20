/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:54:28 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:43:17 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *orig, int c, size_t n)
{
	char	*dst;
	char	*src;
	size_t	i;

	i = 0;
	dst = (char *)dest;
	src = (char *)orig;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == (char)c)
			return (dst + (++i));
		i++;
	}
	return (NULL);
}
