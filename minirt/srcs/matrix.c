/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:31:01 by migarcia          #+#    #+#             */
/*   Updated: 2022/02/02 20:13:28 by migarcia         ###   ########.fr       */
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

t_matrix	m_init(int rows, int cols)
{
	t_matrix a;

	a.m[0][0] = 0;
    a.m[0][1] = 0;
    a.m[0][2] = 0;
    a.m[0][3] = 0;
    a.m[1][0] = 0;
    a.m[1][1] = 0;
    a.m[1][2] = 0;
    a.m[1][3] = 0;
    a.m[2][0] = 0;
    a.m[2][1] = 0;
    a.m[2][2] = 0;
    a.m[2][3] = 0;
    a.m[3][0] = 0;
    a.m[3][1] = 0;
    a.m[3][2] = 0;
    a.m[3][3] = 0;
	a.rows = rows;
	a.cols = cols;
	return (a);
}

t_matrix	m_submatrix(t_matrix	a, int row, int col)
{
	t_matrix	b;
	int		i;
	int		j;
	int		h;
	int		k;

	b.cols = a.cols - 1;
	b.rows = a.rows - 1;
	h = 0;
	i = -1;
	while (++i < a.rows)
	{
		k = 0;
		j = -1;
		while (++j < a.cols)
		{
			b.m[h][k] = a.m[i][j];
			if (j != col)
				k++;
		}
		if (i != row)
			h++;
	}
	return (b);
}

float	m_minor(t_matrix	a, int row, int col)
{
	t_matrix	b;
	float		det;

	b = m_submatrix(a, row, col);
	det = b.m[0][0] * b.m[1][1] - b.m[0][1] * b.m[1][0];
	return (det);	
}

/*float	m_det(t_matrix a, int n) 
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
} */
