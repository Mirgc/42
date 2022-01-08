/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuanena <sjuanena@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:03:40 by sjuanena          #+#    #+#             */
/*   Updated: 2021/04/20 13:16:56 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
/*
 ** Write line by line the specified characters 
 ** and inside the line position by position.
 ** Variable "y" is referring to line # and "x"
 ** is referring to position inside the line.
 */

void	rush(int x, int y)
{
	int	c_x;
	int	c_y;

	c_y = 0;
	while (c_y++ < y && x != 0 && x != 2147483647)
	{	
		c_x = 0;
		while (c_x++ < x)
		{	
			if ((c_x == 1 && c_y == 1) || (c_x == x && c_y == y))
				ft_putchar('o');
			else if ((c_x == x && c_y == 1) || (c_x == 1 && c_y == y))
				ft_putchar('o');
			else if ((c_x > 1 && c_x < x) && (c_y == 1 || c_y == y))
				ft_putchar('-');
			else if ((c_y > 1 && c_y < y) && (c_x == 1 || c_x == x))
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}		
}
