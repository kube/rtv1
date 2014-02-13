/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/27 15:22:31 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/13 02:30:56 by cfeijoo          ###   ########.fr       */
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

typedef struct						s_sphere
{
	t_point							origin;
	float							radius;
	t_color							color;

}									t_sphere;

typedef struct						s_ray
{
	t_point							origin;
	t_vector						direction;
}									t_ray;

#endif
