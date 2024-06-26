/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:38:40 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/19 13:41:37 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	char	c;

	c = 0;
	while (*str != '\0')
	{
		c = *str;
		if ((c < 'A') || (c > 'Z'))
			return (0);
		str++;
	}
	return (1);
}
