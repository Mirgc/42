/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <.@student.42lisboa.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:36:26 by osurcouf          #+#    #+#             */
/*   Updated: 2021/06/28 18:26:57 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : handle errors
** Sends the infos block's malloced' memory to get deleted.
** Prints the Error message.
** Exit cleanly the program.
**
** function : verify_end_line doesn't work yet.
**
** 🦕
*/

void	handle_error(char *error, t_info *infos)
{
	del_mem_infos(infos);
	printf(COLOR_RED "\n	Error\n" COLOR_WHITE "%s\n", error);
	exit(EXIT_SUCCESS);
}

void	error_msg(char *error)
{
	printf(COLOR_RED "\n	Error\n" COLOR_WHITE "%s\n", error);
	exit(EXIT_SUCCESS);
}
