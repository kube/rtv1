/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations_camera.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 00:50:09 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/15 02:18:49 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>
#include <raytracer.h>
#include <math.h>

void			cam_rot_z(t_camera *camera, float angle)
{
	vect_rot_z(&camera->x_axis, angle);
	vect_rot_z(&camera->y_axis, angle);
	vect_rot_z(&camera->z_axis, angle);
}

void			cam_rot_x(t_camera *camera, float angle)
{
	vect_rot_x(&camera->x_axis, angle);
	vect_rot_x(&camera->y_axis, angle);
	vect_rot_x(&camera->z_axis, angle);
}

void			cam_rot_y(t_camera *camera, float angle)
{
	vect_rot_x(&camera->x_axis, angle);
	vect_rot_x(&camera->y_axis, angle);
	vect_rot_x(&camera->z_axis, angle);
}

void			cam_translate(t_camera *camera, float x, float y, float z)
{
	camera->origin.x += x;
	camera->origin.y += y;
	camera->origin.z += z;
}

void			cam_move_to(t_camera *camera, float x, float y, float z)
{
	camera->origin.x = x;
	camera->origin.y = y;
	camera->origin.z = z;
}
