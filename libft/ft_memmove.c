/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:53:19 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/25 18:12:14 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dest, const void *orig, size_t n)
{
	char	*dst;
	char	*src;

	dst = (char *)dest;
	src = (char *)orig;
	if (dest > orig)
	{
		while (n--)
			dst[n] = src[n];
	}
	else
	{
		while (n--)
			*(dst++) = *(src++);
	}
	return (dest);
}
