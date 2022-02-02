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

#include <stdlib.h>
#include <minirt.h>

void	free_mat(float **mat)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

float	**m_multi(t_matrix a, t_matrix b)
{
	int	w;
	int	h;
	int	k;
	float **tmp;

	tmp = (float **)malloc(sizeof(float *) * 4);
        k = 0;
        while (k < 4)
        {
                tmp[k] = (float *)malloc(sizeof(float) * 4);
                k++;
        }
	w = 0;
	while (w < 4)
	{
		h = 0;
		while (h < 4)
		{
			k = 0;
			while (k < 4)
			{
				tmp[w][h] += a.m[w][k] * b.m[k][h];
				k++;
         		}
		h++;
		}
	w++;
	}
	return (tmp);
}

t_tup	m_multi_tup(t_matrix a, t_tup b)
{
	t_tup	tmp;

	tmp.x = a.m[0][0] * b.x + a.m[0][1] * b.y + a.m[0][2] * b.z + a.m[0][3] * b.w;
	tmp.y = a.m[1][0] * b.x + a.m[1][1] * b.y + a.m[1][2] * b.z + a.m[1][3] * b.w;
	tmp.z = a.m[2][0] * b.x + a.m[2][1] * b.y + a.m[2][2] * b.z + a.m[2][3] * b.w;
	tmp.w = a.m[3][0] * b.x + a.m[3][1] * b.y + a.m[3][2] * b.z + a.m[3][3] * b.w;
	return(tmp);
}

t_matrix	m_identity()
{
	t_matrix i;
	int	w;
	int	h;
	
	w = -1;
	while (++w < 4)
	{
		h = -1;
		while (++h < 4)
		{
			if (h == w)
				i.m[w][h] = 1;
			else
				i.m[w][h] = 0;
		}
	}
	return (i);
}

t_matrix	m_trans(t_matrix a)
{
	t_matrix tmp;
	int	w;
	int	h;
	
	w = -1;
	while (++w < 4)
	{
		h = -1;
		while (++h < 4)
		{
			tmp.m[h][w] = a.m[w][h];
		}
	}
	return (tmp);
}

float	m_det(t_matrix a, int n) 
{ 
	float	c;
	float	r;
	int	i;
	int	k;
	int	j;
	
	i = -1;
	while (++i < n)
	{
		k = i;
		while (++k < n)
		{
            		c = a.m[k][i] / a.m[i][i];
			j = i - 1;
			while (++j < n)
				a.m[k][j]= a.m[k][j] - c*a.m[i][j];
        	}
    	}
	r = 1;
	i = -1;
	while (++i < n)
        	r *=a.m[i][i];
	return r;
} 
