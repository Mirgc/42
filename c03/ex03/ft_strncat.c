/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:12:12 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/20 16:25:57 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*chdest;
	char	*chsrc;

	chdest = dest;
	chsrc = src;
	while (*chdest)
	{
		chdest++;
	}
	while (nb > 0 && *chsrc)
	{
		*chdest = *chsrc;
		chdest++;
		chsrc++;
		nb--;
	}
	*chdest = '\0';
	return (dest);
}
