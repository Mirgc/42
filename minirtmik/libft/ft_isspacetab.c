/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspacetab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:14:06 by migarcia          #+#    #+#             */
/*   Updated: 2022/04/05 18:14:56 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspacetab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
