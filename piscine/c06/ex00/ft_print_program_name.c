/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 08:01:07 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/26 11:19:24 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;

	(void) argc;
	str = *argv;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
	return (0);
}
