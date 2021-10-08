/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 21:08:53 by oldurosi          #+#    #+#             */
/*   Updated: 2020/01/20 15:36:43 by oldurosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../minilibx_x11/mlx.h"
//# include "./keys.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# define P_WIDTH  1080
# define P_HEIGHT 720
//# define ALTI_ZOOM 10
# define MAX_ZOOM 5
# define MAGNIFY 2

typedef	struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_map
{
    int     **matrix;
    int     width;
    int     height;
    int     coord_x;
    int     coord_y;
    int     x0;
    int     x1;
    int     y0;
    int     y1;
    int     zoom;
    int     isometric;
    double  z_value;
    double  angle_x;
    double  angle_y;
	t_mlx	mlx;
	t_image	image;
	t_color	color;
}				t_map;

long			isisnum(char *str);
void			ft_error(char *str);
int         	map_draw(t_map *map);
void			read_lines(char *argv0, t_map *map);
void			nomalize_map(t_map *map);
void			fill_matrix(t_map *map, int x, int y, char *line);
void			validate(char *line);
int				count_values(char *line);
void			mix_color(t_map *map);
void			print_string(t_map *map);
int				line_count(char *argv, t_map *map);

#endif
