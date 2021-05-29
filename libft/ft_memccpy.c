/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:54:28 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/28 15:33:28 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memccpy(void *dest, const void *orig, int c, size_t n)
{
	char	*dst;
	char	*src;
	int		i;

	i = 0;
	dst = (char *)dest;
	src = (char *)orig;
	while (n-- && i == 0)
	{
		if (*src == (char)c)
			i = 1;
		*(dst++) = *(src++);
	}
	return (dest);
}
