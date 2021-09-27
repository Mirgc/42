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
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	int width;
	int height;
	int **matrix;
	void *mlx_ptr;
	void *win_ptr;
} t_map;

void    draw_map(t_map *map);
#endif
