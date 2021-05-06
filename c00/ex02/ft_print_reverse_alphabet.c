/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:40:42 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/17 08:42:26 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet (void)
{
	char	i;

	i = 'z';
	while (i >= 'a')
	{
		write (1, &i, sizeof(i));
		i--;
	}
}
