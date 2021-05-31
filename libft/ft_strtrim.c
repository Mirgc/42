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
int	ft_check_ch(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}	
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		len;
	int		lenend;
	int		a;
	int		b;

	len = ft_strlen(set);
	lenend = ft_strlen(s1);
	a = 0;
	while (a < len)
	{
		if (ft_check_ch(*s1, set) == 0)
			break;
		s1++;
		a++;
	}
	printf("----%i\n",a);
	b = 0;
	while (b < len)
	{
		if (ft_check_ch(s1[lenend], set) == 0)
			break;
		lenend--;
		b++;
	}
	dst = (char *) malloc (((lenend - a) - b) * sizeof(char));
	if (!dst)
		return (NULL);
	dst = ft_substr(s1, a, (lenend -a) - b);
	return (dst);
}
