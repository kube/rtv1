/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:22:31 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/16 16:58:58 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# define SPHERE_OBJECT 0
# define CYLINDER_OBJECT 1

typedef union						u_color
{
	struct
	{
		unsigned char				blue;
		unsigned char				green;
		unsigned char				red;
		char						opacity;
	};
	int								color;
}									t_color;

typedef struct						s_point
{
	float							x;
	float							y;
	float							z;
}									t_point;

typedef struct						s_vector
{
	float							x;
	float							y;
	float							z;
}									t_vector;





typedef struct						s_cylinder
{
	t_point							origin;
	float							radius;
	t_color							color;
	float							rot_x;
	float							rot_y;
	float							rot_z;
}									t_cylinder;


typedef struct						s_sphere
{
	t_point							origin;
	float							radius;
	t_color							color;
	float							rot_x;
	float							rot_y;
	float							rot_z;
}									t_sphere;


typedef struct						s_object 
{
	int								type;
	union
	{
		t_sphere					sphere;
		t_cylinder					cylinder;
	};
}									t_object;




typedef struct						s_ray
{
	t_point							origin;
	t_vector						direction;
}									t_ray;

typedef struct						s_camera
{
	t_point							origin;
	t_vector						x_axis;
	t_vector						y_axis;
	t_vector						z_axis;
}									t_camera;

#endif
