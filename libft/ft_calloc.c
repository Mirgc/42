/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:18:38 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/28 15:18:40 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_calloc(size_t n, size_t size)
{
	void	*buff;

	buff = (char *) malloc(n * size);
	if (!buff)
		return (0);
	return (ft_memset(buff, '0', size));
}
