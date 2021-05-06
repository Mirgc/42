/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:11:35 by iibanez-          #+#    #+#             */
/*   Updated: 2021/05/04 20:01:28 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# define BUFF 512
typedef struct s_map
{
	int				size;
	char			empty_c;
	char			full_c;
	char			obstacle_c;
	int				**tab;
	int				r_size;
	int				resolved;
}	t_map;
# include "map.c"
# include "ft_parse_lines.c"
# include "ft_parse_map.c"
# include "ft_check_diagonals.c"
# include "ft_array_utils.c"
# include "ft_validations.c"
# include "ft_decision_tree.c"
# include "ft_read_file.c"
int				ft_get_table_d1_max(t_map *map);
int				ft_get_table_d2_max(t_map *map);
int				ft_get_table_d3_max(t_map *map);
int				ft_get_table_d4_max(t_map *map);
struct s_map	*ft_copy(t_map *map);
struct s_map	*ft_parse_lines(int l_n, char *str, int line_s, t_map *map);
struct s_map	*ft_parse_str_to_map(char *str);
struct s_map	*set_map(unsigned int size, char empty_c,
					char full_c, char obstacle_c);
struct s_map	*set_error_map(void);
void			ft_printf_dia(t_map *map);
int				ft_validation(t_map *map);
void			ft_save_map(t_map *map_c1, t_map *map_c2);
void			ft_decision_tree(t_map *map_c1, t_map *map_c2);
char    *ft_read_file(char *argv);
#endif
