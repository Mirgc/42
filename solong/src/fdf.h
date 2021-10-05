/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:14:52 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/27 18:13:10 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_x11/mlx.h"
# define P_WIDTH  1080
# define P_HEIGHT 720
# define ALTI_ZOOM 10
# define MAX_ZOOM 5
# define MAGNIFY 2


typedef struct  s_mlx
{
    void    *init;
    void    *win;
    void    *img;
} t_mlx;

typedef struct  s_image
{
    char    *data;
    int     size;
    int     endian;
    int     bpp;
} t_image;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_map
{
	int width;
	int height;
	int **matrix;
	int y0;
    int y1;
    int x0;
	int x1;
	int coord_x;
	int	coord_y;
	int	scalin;
	int		isometric;
	double	z_value;
	double		angle_y;
	double		angle_x;
	t_mlx mlx;
	t_image img;
	t_color color;
} t_map;

int	draw_map(t_map *map);
int	read_map(char *argv, t_map *map);
#endif
