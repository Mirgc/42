/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:21:49 by osurcouf          #+#    #+#             */
/*   Updated: 2021/05/05 14:21:51 by osurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 🦕
**
** function : Quadratic
**
**	1. Function to solve the quadratic equation.
**		Used for the sphere and the cylinder.
**
**		discriminant = 2(b * b) - 4a * c
**
**		Note : (I got rid of the 2 and 4 because from what
**				I understand, I'm already handling the proportions
**				already in camera_ray.c. Same after.)
**
**		Then the result will be either
**
**				t = -2b - sqrt(discriminant) / a
**				t = -2b + sqrt(discriminant) / a
**
**		In the case of the sphere we keep the positive one
**		In the case of the cylinder, we'll keep the
**			closest one that's positive.
**		Also, I'm swaping t0 and t1 so that t0 is always the lowest
**		number so that there's isn't any troubles when running the
**		code to check which one is the right solution for the cylinder.
**
** 🦕
*/

t_params	new_params(float a, float b, float c)
{
	t_params	params;

	params.a = a;
	params.b = b;
	params.c = c;
	return (params);
}

bool	solve_quadratic(t_params param, float *t0, float *t1)
{
	float	discriminant;
	float	temp;

	discriminant = (param.b * param.b) - (param.a * param.c);
	if (discriminant < 0)
		return (false);
	else if (discriminant == 0)
	{
		*t0 = param.b / param.a;
		*t1 = param.b / param.a;
	}
	else
	{
		*t0 = (-param.b - sqrt(discriminant)) / param.a;
		*t1 = (-param.b + sqrt(discriminant)) / param.a;
	}
	if (*t0 > *t1)
	{
		temp = *t0;
		*t0 = *t1;
		*t1 = temp;
	}
	return (true);
}
