/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:14:52 by migarcia          #+#    #+#             */
/*   Updated: 2021/09/24 19:28:23 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_map
{
	int width;
	int height;
	int **matrix;
	void *mlx_ptr;
	void *win_ptr;
} t_map;

#endif
