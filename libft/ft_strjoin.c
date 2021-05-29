/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:11:23 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/28 17:21:28 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		len;

	len = (ft_strlen(s1)) + ft_strlen(s2) + 1;
	dst = (char *) malloc(len * sizeof(char));
	ft_strlcat(dst, s1, len);
	ft_strlcat(dst, s2, len);
	return (dst);
}
