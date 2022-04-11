/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:11:23 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/09 18:40:38 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		len;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1)) + ft_strlen(s2) + 1;
	dst = malloc(len * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	ft_memmove(dst, s1, len);
	ft_memmove(dst + ft_strlen(s1), s2, len);
	dst[len] = '\0';
	return (dst);
}
