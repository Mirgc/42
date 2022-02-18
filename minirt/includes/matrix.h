#ifndef MATRIX_H
#define MATRIX_H

# include "structs.h"
# include <math.h>

void		print_matrix(t_matrix m);
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
t_matrix	m_rotationx(int angle);
t_matrix	m_rotationy(int angle);
t_matrix	m_rotationz(int angle);
t_matrix	m_shearing(float xy, float xz, float yx, float yz, float zx, float zy);

#endif
