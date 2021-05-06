/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:04:42 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/18 19:56:50 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	swap;
	int	i;
	int	j;

	swap = 0;
	i = -1;
	while (i++ < size - 1)
	{
		j = i;
		while (j++ < size - 1)
		{
			if (*(tab + i) >= *(tab + j))
			{
				swap = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = swap;
			}
		}
	}
}
