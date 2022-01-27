/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:15:04 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/27 20:16:52 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/tuples.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_tup	a;
	t_tup	b;
	t_tup	c;
	t_tup	d;

	a = v_create(1, 2, 3, 0);
	b = v_create(2, 3, 4, 0);
	c = v_add(a, b);
	d = v_create(1, 2, 3, 0);

	printf("%f, %f, %f, %i\n", a.x, a.y, a.z, a.w);
	printf("%f, %f, %f, %i\n", b.x, b.y, b.z, b.w);
	printf("%f, %f, %f, %i\n", c.x, c.y, c.z, c.w);
	c = v_substract(a, b);
	printf("%f, %f, %f, %i\n", c.x, c.y, c.z, c.w);
	c = v_negate(a);
	printf("%f, %f, %f, %i\n", c.x, c.y, c.z, c.w);
	c = v_multi(a, 0.5);
	printf("%f, %f, %f, %i\n", c.x, c.y, c.z, c.w);
	printf("Magnitude: %f\n", v_magnitude(d));
	c = v_normalize(d);
	printf("%f, %f, %f, %i\n", c.x, c.y, c.z, c.w);
	printf("Magnitude: %f\n", v_magnitude(c));
	printf("Dot: %f\n", v_dot(a, b));
	c = v_cross(b, a);
	printf("%f, %f, %f, %i\n", c.x, c.y, c.z, c.w);
}
