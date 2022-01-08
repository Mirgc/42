/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 10:29:34 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/20 16:23:53 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*chdest;
	char	*chsrc;

	chdest = dest;
	chsrc = src;
	while (*chdest)
	{
		chdest++;
	}
	while (*chsrc)
	{
		*chdest = *chsrc;
		chdest++;
		chsrc++;
	}
	*chdest = '\0';
	return (dest);
}
