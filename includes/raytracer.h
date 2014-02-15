/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 00:24:38 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/15 02:10:06 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# define VIEWPLANE_PLOT 1000

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	int						bpp;
	int						size_line;
	int						endian;
	int						*data;

	t_camera				camera;
	unsigned int			view_width;
	unsigned int			view_height;
}							t_env;

typedef union
{
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		char			opacity;
	};
	int					color;
}						u_color;

void	cam_rot_z(t_camera *camera, float angle);
void	cam_rot_x(t_camera *camera, float angle);
void	cam_rot_y(t_camera *camera, float angle);
void	cam_translate(t_camera *camera, float x, float y, float z);
void	cam_move_to(t_camera *camera, float x, float y, float z);

void	vect_rot_z(t_vector *vector, float angle);
void	vect_rot_x(t_vector *vector, float angle);
void	vect_rot_y(t_vector *vector, float angle);
void	vect_scale(t_vector *vector, float coeff);

#endif
