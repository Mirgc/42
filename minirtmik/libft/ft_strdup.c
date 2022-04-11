/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:15:48 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:42:11 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		len;

	len = ft_strlen(s) + 1;
	d = (char *) malloc(len);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}
