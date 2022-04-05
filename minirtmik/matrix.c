/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:31:01 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/31 21:08:42 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		m_multi_array(float *a, float *b)
{
	float tmp;

	while(*a && *b)
	{
		tmp += *a * *b;
		a++;
		b++;
	}
	return (tmp);
}

float	**m_multi(float **a, float **b)
{
	int	w;
	int	h;
	int i;
	float **tmp;

	w = -1;
	h = -1;
	while (a[++w])
	{
		i = 0;
		while (b[++h])
			tmp[w][h] = m_multi_array(a[w], b[h]);
	}
	return (tmp);
}
