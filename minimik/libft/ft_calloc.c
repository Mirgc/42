/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:18:38 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:46:53 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*buff;
	size_t	spac;

	if (size == 0)
		spac = n;
	else
		spac = n * size;
	buff = (char *) malloc(spac);
	if (!buff)
		return (NULL);
	return (ft_memset(buff, 0, spac));
}
