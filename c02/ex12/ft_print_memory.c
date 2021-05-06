/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:14:50 by migarcia          #+#    #+#             */
/*   Updated: 2021/04/21 10:03:21 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write (1, &c, 1);
		i++;
	}
}

/*void	ft_print_direchex(void *addr)
{
	unsigned long long	i;
	int	j;

	i = addr;

}*/

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*c;
	unsigned int	i;
	unsigned int	sensize;

	i = 0;
	c = addr;
	while (i * 16 < size)
		sensize = 16;
	if (i < size / 16)
		sensize = 16;
	else
		sensize = size % 16;
	while (*c)
		ft_putchar((char)(unsigned long long) c, sensize);
	return (0);
}
