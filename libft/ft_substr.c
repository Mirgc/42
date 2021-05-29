/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:13:50 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/28 16:51:13 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	dst = (char *) malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (len --)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	return (dst);
}
