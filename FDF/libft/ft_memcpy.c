/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:02:16 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:43:10 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *orig, size_t n)
{
	char	*src;
	char	*dst;

	src = (char *)orig;
	dst = (char *)dest;
	if (!dest && !orig)
		return (0);
	while (n--)
		*(dst++) = *(src++);
	return (dest);
}
