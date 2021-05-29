/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:48:21 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/26 18:42:00 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	while (++i < dstsize)
		*(dst + i) = *(src + i);
	dst[i - 1] = '\0';
	return (ft_strlen(src));
}
