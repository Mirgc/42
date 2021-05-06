/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:42:19 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/18 19:14:34 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	swap;
	int	i;
	int	j;

	swap = 0;
	i = -1;
	while (i++ < (size - 1))
	{
		j = i;
		while (j++ < (size - 1))
		{
			swap = *(tab + i);
			*(tab + i) = *(tab + j);
			*(tab + j) = swap;
		}
	}
}
