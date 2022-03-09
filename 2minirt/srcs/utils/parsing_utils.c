/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:42:00 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/30 17:13:34 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : parsing utilities
**
**	1. Next_nbr
**		- Moves the cursor from a number to the next while
**			taing into account '-', '+', ','
**	2. Pass_spaces
**		- Passes spaces to naviguate from one block to the
**			other.
**	3. Get_color
**		- Since that particular piece of code was repetitive,
**			I put it aside. Gets the 'r,g,b' block.
**	4. Get_caps
**		- To get a full cylinder (and not just the tube part),
**			I couldn't find another way than to make circles
**			exactly in the right spot for the caps. They are
**			added to the object array, like any other object.
**		Note : if I have the time and motivation, I'll add
**				circles to the list of object you can parse
**				through in the scene.rt file.
**
** 🦕
*/

char	*next_nbr(char *line, t_info *infos)
{
	char	*o_line;

	o_line = line;
	if (*line == '-')
		line++;
	while (*line && (ft_isdigit(*line)))
		line++;
	if (*line && *line == '.')
	{
		line++;
		if (*line && (*line == ',' || is_space(line)))
			handle_error("🔢	A decimal number is missing digit(s) after '.'\n",
				infos);
	}
	while (*line && ft_isdigit(*line))
		line++;
	if ((ft_isdigit(*(line + 1)) || *(line + 1) == '-') && *line == ',')
		line++;
	if (line == o_line)
		handle_error("🔢	Random character lost somewhere in file :s\n",
			infos);
	return (line);
}

char	*next_int(char *line, t_info *infos)
{
	char	*o_line;

	o_line = line;
	if (*line == '-')
		line++;
	while (*line && (ft_isdigit(*line)))
		line++;
	if (*line == '.')
		handle_error("🔢	You let a '.' next to an integer.\n", infos);
	if (*line && *line + 1
		&& ((ft_isdigit(*(line + 1)) || *(line + 1) == '-')
			&& *line == ','))
		line++;
	if (line == o_line)
		handle_error("🔢	Random character lost somewhere in file :s\n",
			infos);
	return (line);
}

bool	is_space(char *line)
{
	if (*line == SPACE || *line == TAB)
		return (true);
	return (false);
}

char	*pass_spaces(char *line, t_info *infos)
{
	char	*o_line;

	o_line = line;
	while (is_space(line))
		line++;
	if (line == o_line)
		handle_error("⌨️	There's a lonely character attached to a number.\n",
			infos);
	return (line);
}

void	verify_end_line(char *line, t_info *infos)
{
	while (*line && is_space(line))
		line++;
	if (*line != END && *line != COMMENT && *line != '\0')
		handle_error("	You have wandering character(s) at the end of a line.\n",
			infos);
}
