/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:13:40 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/19 13:30:33 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c = (int)*str;
		if ((c < 48) || (c > 57))
			return (0);
		str++;
	}
	return (1);
}
