/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_vectors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 14:09:42 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/16 00:49:17 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>
#include <raytracer.h>
#include <math.h>

#include <stdio.h>

void			vect_rot_z(t_vector *vector, float angle)
{
	t_point		a;

	a.x = vector->x;
	a.y = vector->y;
	vector->x = a.x * cos(angle) - a.y * sin(angle);
	vector->y = a.x * sin(angle) + a.y * cos(angle);
}

void			vect_rot_x(t_vector *vector, float angle)
{
	t_point		a;

	a.y = vector->y;
	a.z = vector->z;
	vector->y = a.y * sin(angle) + a.z * cos(angle);
	vector->z = a.y * cos(angle) - a.z * sin(angle);
}

void			vect_rot_y(t_vector *vector, float angle)
{
	t_point		a;

	a.x = vector->x;
	a.z = vector->z;
	vector->x = a.z * sin(angle) + a.x * cos(angle);
	vector->z = a.z * cos(angle) - a.x * sin(angle);
}

void			vect_scale(t_vector *vector, float coeff)
{
	vector->x *= coeff;
	vector->y *= coeff;
	vector->z *= coeff;
}
