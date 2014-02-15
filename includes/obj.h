/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:22:31 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/16 00:53:25 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

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

typedef struct						s_pont
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

typedef struct						s_sphere
{
	t_point							origin;
	t_vector						radius;
	t_color							color;

}									t_sphere;

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
