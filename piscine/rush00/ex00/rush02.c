/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuanena <sjuanena@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:04:42 by sjuanena          #+#    #+#             */
/*   Updated: 2021/04/18 13:42:56 by migarcia         ###   ########.fr       */
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
	while (c_y++ < y && x != 0)
	{	
		c_x = 0;
		while (c_x++ < x)
		{	
			if ((c_x == 1 && c_y == 1) || (c_x == x && c_y == 1))
				ft_putchar('A');
			else if ((c_x == 1 && c_y == y) || (c_x == x && c_y == y))
				ft_putchar('C');
			else if ((c_x > 1 && c_x < x) && (c_y == 1 || c_y == y))
				ft_putchar('B');
			else if ((c_y > 1 && c_y < y) && (c_x == 1 || c_x == x))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}		
}
