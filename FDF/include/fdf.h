/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:55:01 by migarcia          #+#    #+#             */
/*   Updated: 2021/10/23 10:14:34 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define P_MENU  1280
# define P_WIDTH  1080
# define P_HEIGHT 720
# define TEXT_COLOR 0xEAEAEA

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct s_color
{
	int		t;
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct s_map
{
	int		**matrix;
	int		width;
	int		height;
	int		coord_x;
	int		coord_y;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		zoom;
	int		isometric;
	double	z_value;
	double	angle_x;
	double	angle_y;
	t_mlx	mlx;
	t_image	image;
	t_color	color;
}				t_map;

void	rotate_x(t_map *map);
void	rotate_y(t_map *map);
void	ft_error(char *str);
int		map_draw(t_map *map);
void	map_read(char *str, t_map *map);
void	nomalize_map(t_map *map);
void	print_menu(t_map *map);

#endif
