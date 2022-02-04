#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "tuples.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define EPSILON 0.00001
# define P_WIDTH 900 
# define P_HEIGHT 550

typedef struct s_matrix
{
	float m[4][4];
	int	rows;
	int	cols;
}	t_matrix;

typedef struct s_color
{
        double  r;
        double  g;
        double  b;
} t_color;

typedef struct  s_mlx
{
        void    *init;
        void    *win;
        void    *img;
}                               t_mlx;

typedef struct  s_image
{
        char    *data;
        int     size;
        int     endian;
        int     bpp;
        int     *px_img;
}                               t_image;

typedef struct  s_map
{
        int     width;
        int     height;
        t_mlx   mlx;
        t_image image;
        t_color color;
}                               t_map;

t_color addcolor(t_color a, t_color b);
t_color subcolor(t_color a, t_color b);
t_color multicolor(t_color a, int b);
t_color hadacolor(t_color a, t_color b);
void		free_mat(float **mat);
t_matrix	m_init(int rows, int cols);
t_matrix	m_multi(t_matrix a, t_matrix b);
t_tup		m_multi_tup(t_matrix a, t_tup b);
t_matrix	m_identity(void);
t_matrix	m_trans(t_matrix a);
t_matrix	m_submatrix(t_matrix	m, int row, int col);
float		m_minor(t_matrix    a, int row, int col, int c);
float		m_cofactor(t_matrix     a, int row, int col, int c);
float		m_det(t_matrix	a, int c);
t_matrix	m_invertible(t_matrix a);
t_matrix	m_translation(float x, float y, float z);
t_matrix	m_scaling(float x, float y, float z);
t_matrix	m_rotationx(float rad);
//float   m_det(t_matrix a, int n);

#endif
