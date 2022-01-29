/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:15:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/29 12:36:52 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tuples.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_proj	p;
	t_env	e;

	p.pos = v_create(0, 1, 0, 0);
	p.vel = v_normalize(v_create(1, 1, 0, 1));
	e.grav = v_create(0, -0.1, 0, 1);
	e.wind = v_create(-0.01, 0, 0, 1);

	int i = 0;
	while(p.pos.y > 0)
	{
		p = tick(e, p);
		printf("%i - pos.x: %f, pos.y: %f, pos.z: %f\n", i++, p.pos.x, p.pos.y, p.pos.z);
	}
}
