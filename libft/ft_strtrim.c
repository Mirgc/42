/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:21:48 by migarcia          #+#    #+#             */
/*   Updated: 2021/05/28 18:45:51 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		len;
	int		lenend;
	int		a;
	int		b;

	len = ft_strlen(set);
	lenend = ft_strlen(s1);
	if (!(ft_strncmp(s1, set, len)))
		a = len;
	else
		a = 0;
	if (!(ft_strncmp(s1 + (lenend - len), set, len)))
		b = (lenend - len) - a;
	else
		b = lenend;
	dst = (char *) malloc ((b - a) * sizeof(char));
	if (!dst)
		return (NULL);
	dst = ft_substr(s1, a, b);
	return (dst);
}
