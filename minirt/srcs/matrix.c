/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:31:01 by migarcia          #+#    #+#             */
/*   Updated: 2022/02/18 20:31:45 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <matrix.h>

void	print_matrix(t_matrix m)
{
	int	w;
	int	h;

        w = 0;
        while (w < 4)
        {
                h = 0;
                while (h < 4)
                {
                        printf("%0.5f ", m.m[w][h]);
                        h++;
                }
                printf("\n");
                w++;
        }
}

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

t_matrix	m_init_with_tuple(t_tup a, t_tup b, t_tup c)
{
	t_matrix        m;

	m.m[0][0] = a.x;
	m.m[0][1] = a.y;
	m.m[0][2] = a.z;
	m.m[0][3] = 0;
	m.m[1][0] = b.x;
	m.m[1][1] = b.y;
	m.m[1][2] = b.z;
	m.m[1][3] = 0;
	m.m[2][0] = c.x;
	m.m[2][1] = c.y;
	m.m[2][2] = c.z;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	m.rows = 4;
	m.cols = 4;
	return (m);
}

t_matrix	m_multi(t_matrix a, t_matrix b)
{
	int		w;
	int		h;
	int		k;
	t_matrix 	tmp;

	tmp = m_init(4, 4);
	w = 0;
	while (w < 4)
	{
		h = 0;
		while (h < 4)
		{
			k = 0;
			while (k < 4)
			{
				tmp.m[w][h] += a.m[w][k] * b.m[k][h];
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

	tmp.x = b.x * a.m[0][0] + b.y * a.m[0][1] + b.z * a.m[0][2] + b.w * a.m[0][3];
	tmp.y = b.x * a.m[1][0] + b.y * a.m[1][1] + b.z * a.m[1][2] + b.w * a.m[1][3];
	tmp.z = b.x * a.m[2][0] + b.y * a.m[2][1] + b.z * a.m[2][2] + b.w * a.m[2][3];
	tmp.w = b.x * a.m[3][0] + b.y * a.m[3][1] + b.z * a.m[3][2] + b.w * a.m[3][3];
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
	i.rows = 4;
	i.cols = 4;
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

float	m_minor(t_matrix	a, int row, int col, int c)
{
	t_matrix	b;
	float		det;

	det = 0;
	b = m_submatrix(a, row, col);
	det += m_det(b, c - 1);
	return (det);	
}

float	m_cofactor(t_matrix	a, int row, int	col, int c)
{
	if ((row + col) % 2)
		return(m_minor(a, row, col, c) * -1);
	else
		return(m_minor(a, row, col, c) * 1);
}

float	m_det(t_matrix	a, int	c)
{
	float	det;
	int	i;

	det = 0;
	i = -1;
	if (c == 2)
		det += a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
	else
	{
		while (++i < c)
			det += a.m[0][i] * m_cofactor(a, 0, i, c);
	}
	return (det);
}

t_matrix	m_invertible(t_matrix a)
{
	t_matrix	b;
	float		det;
	int		i;
	int		j;

	b = m_init(4, 4);
	det = m_det(a, 4);
	if (det != 0.0)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
			{
				b.m[j][i] = m_cofactor(a, i, j, 4) / det;
			}
		}	
	}
	else
	{
		b.cols = 0;
		b.rows = 0;
	}
	return (b);
}

t_matrix	m_translation(float x, float y, float z)
{
	t_matrix	a;

	a = m_identity();
	a.m[0][3] = x;
	a.m[1][3] = y;
	a.m[2][3] = z;
	return (a);
}

t_matrix	m_scaling(float	x, float y, float z)
{
	t_matrix	a;
	
	a = m_identity();
	a.m[0][0] = x;
	a.m[1][1] = y;
	a.m[2][2] = z;
	return (a);
}

t_matrix	m_rotationx(float angle)
{
	t_matrix	a;
	float		rad;

	rad = angle;// * M_PI / 180;
	a = m_identity();
	a.m[1][1] = cos(rad);
	a.m[1][2] = sin(rad) * -1.0f;
	a.m[2][1] = sin(rad);
	a.m[2][2] = cos(rad);
	return (a);
}

t_matrix	m_rotationy(float angle)
{
	t_matrix	a;
	float		rad;

	rad = angle;// * M_PI / 180;
	a = m_identity();
	a.m[0][0] = cos(rad);
	a.m[0][2] = sin(rad);
	a.m[2][0] = sin(rad) * -1.0f;
	a.m[2][2] = cos(rad);
	return (a);
}

t_matrix	m_rotationz(float angle)
{
	t_matrix	a;
	float		rad;

	rad = angle;// * M_PI / 180;
	a = m_identity();
	a.m[0][0] = cos(rad);
	a.m[0][1] = sin(rad) * -1.0f;
	a.m[1][0] = sin(rad);
	a.m[1][1] = cos(rad);
	return (a);
}

t_matrix	m_shearing(float xy, float xz, float yx, float yz, float zx, float zy)
{
	t_matrix	a;

	a = m_identity();
	a.m[0][1] = xy;
	a.m[0][2] = xz;
	a.m[1][0] = yx;
	a.m[1][2] = yz;
	a.m[2][0] = zx;
	a.m[2][1] = zy;
	return (a);	
}
