/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:03:08 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/13 16:42:39 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>

static int			solve_quadratic(float a, float b, float c, float x0, float x1)
{
	float			discr;
	float			q;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
		x1 = - 0.5 * b / a;
		x0 = x1;
	else
	{
		q = (b > 0)? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
		x0 = q / a;
		x1 = c / q;
	}
	if (x0 > x1)
		std::swap(x0, x1);
	return (1);
}

static int			ray_intersects_sphere(t_ray *ray, t_sphere *sphere)
{
	return (0);
}

int					main(void)
{

	return (0);
}
