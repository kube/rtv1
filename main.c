/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeijoo <cfeijoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 11:03:08 by cfeijoo           #+#    #+#             */
/*   Updated: 2014/02/16 00:39:16 by cfeijoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj.h>
#include <raytracer.h>
#include <math.h>
#include <mlx.h>

#include <stdlib.h>

#include <stdio.h>

// TO ADD IN MAKEFILE
#include "/opt/X11/include/X11/X.h"


#define WIN_WIDTH 1200
#define WIN_HEIGHT 600

static void			pixel_to_image(t_env *env, t_point a, int color)
{
	unsigned int	i;

	i = env->view_width * (unsigned int)a.y + (unsigned int)a.x;
	if (i < env->view_width * env->view_height && (int)a.y >= 0 && (int)a.x >= 0
		&& (unsigned int)a.x < env->view_width)
		env->data[i] = color;
}

static int			blend_colors(int color1, int color2, float coeff)
{
	u_color			ucolor1;
	u_color			ucolor2;
	u_color			new_color;

	ucolor1.color = color1;
	ucolor2.color = color2;
	new_color.red = ucolor1.red * (1 - coeff) + ucolor2.red * coeff;
	new_color.green = ucolor1.green * (1 - coeff) + ucolor2.green * coeff;
	new_color.blue = ucolor1.blue * (1 - coeff) + ucolor2.blue * coeff;
	return (new_color.color);
}


// static int			solve_quadratic(float a, float b, float c, float x0, float x1)
// {
// 	float			discr;
// 	float			q;

// 	discr = b * b - 4 * a * c;
// 	if (discr < 0)
// 		return (0);
// 	else if (discr == 0)
// 		x1 = - 0.5 * b / a;
// 		x0 = x1;
// 	else
// 	{
// 		q = (b > 0)? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
// 		x0 = q / a;
// 		x1 = c / q;
// 	}
// 	if (x0 > x1)
// 		std::swap(x0, x1);
// 	return (1);
// }

// static int			ray_intersects_sphere(t_ray *ray, t_sphere *sphere)
// {
	
// 	return (0);
// }

// static void			throw_ray(t_env *env, unsigned int i, unsigned int j,
// 								t_ray *ray)
// {

// }

static int		keypress_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65363)
		cam_rot_z(&env->camera, M_PI / 20);
	if (keycode == 65361)
		cam_rot_z(&env->camera, -M_PI / 20);
	if (keycode == 65362)
		cam_rot_y(&env->camera, M_PI / 20);
	if (keycode == 65364)
		cam_rot_y(&env->camera, -M_PI / 20);
	printf("Camera : %f %f %f\n", env->camera.x_axis.x, env->camera.x_axis.y,
			env->camera.x_axis.z);
	return (0);
}

static void			trace_color(t_env *env, unsigned int i, unsigned int j,
								t_ray *ray)
{
	float			length;
	t_point			a;

	a.x = i;
	a.y = j;
	length = sqrt(ray->direction.x * ray->direction.x + ray->direction.y
		* ray->direction.y + ray->direction.z * ray->direction.z) - 1;
	pixel_to_image(env, a, blend_colors(0xFFFFFF, 0xFE25ED, length));
}

static int			throw_view_plane(t_env *env)
{
	unsigned int	i;
	unsigned int	j;
	t_ray			ray;

	i = 0;
	j = 0;
	ray.origin.x = env->camera.origin.x;
	ray.origin.y = env->camera.origin.y;
	ray.origin.y = env->camera.origin.z;

	ray.direction.x = env->camera.x_axis.x;
	ray.direction.y = env->camera.x_axis.y;
	ray.direction.z = env->camera.x_axis.z;

	ray.direction.x -= (env->camera.y_axis.x / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.y -= (env->camera.y_axis.y / VIEWPLANE_PLOT) * env->view_width / 2;
	ray.direction.z -= (env->camera.y_axis.z / VIEWPLANE_PLOT) * env->view_width / 2;

	ray.direction.x -= (env->camera.z_axis.x / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.y -= (env->camera.z_axis.y / VIEWPLANE_PLOT) * env->view_height / 2;
	ray.direction.z -= (env->camera.z_axis.z / VIEWPLANE_PLOT) * env->view_height / 2;

	while (j < env->view_height)
	{
		i = 0;
		while (i < env->view_width)
		{
			// TREAT RAY HERE
			// throw_ray(env, i, j, &ray);
			trace_color(env, i, j, &ray);

			// END TREAT RAY
			ray.direction.x += (env->camera.y_axis.x / VIEWPLANE_PLOT); 
			ray.direction.y += (env->camera.y_axis.y / VIEWPLANE_PLOT);
			ray.direction.z += (env->camera.y_axis.z / VIEWPLANE_PLOT);
			i++;
		}
		ray.direction.x += (env->camera.z_axis.x / VIEWPLANE_PLOT); 
		ray.direction.y += (env->camera.z_axis.y / VIEWPLANE_PLOT);
		ray.direction.z += (env->camera.z_axis.z / VIEWPLANE_PLOT);

		// BACK TO ZERO ON Y-AXIS
		ray.direction.x -= (env->camera.y_axis.x / VIEWPLANE_PLOT) * env->view_width; 
		ray.direction.y -= (env->camera.y_axis.y / VIEWPLANE_PLOT) * env->view_width;
		ray.direction.z -= (env->camera.y_axis.z / VIEWPLANE_PLOT) * env->view_width;
		j++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}


static void			init_cam(t_camera *cam, float x, float y, float z)
{
	cam->x_axis.x = 1.0f;
	cam->x_axis.y = 0.0f;
	cam->x_axis.z = 0.0f;
	cam->y_axis.x = 0.0f;
	cam->y_axis.y = 1.0f;
	cam->y_axis.z = 0.0f;
	cam->z_axis.x = 0.0f;
	cam->z_axis.y = 0.0f;
	cam->z_axis.z = 1.0f;
	cam->origin.x = x;
	cam->origin.y = y;
	cam->origin.z = z;
}

static void			init_cam_angle(t_camera *cam, float y, float z)
{
	cam_rot_y(cam, y);
	cam_rot_z(cam, z);
}

int					main(void)
{
	t_env			env;

	env.view_width = WIN_WIDTH;
	env.view_height = WIN_HEIGHT;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.view_width, env.view_height, "RayTracer");
	env.img = mlx_new_image(env.mlx, env.view_width, env.view_height);
	env.data = (int*)mlx_get_data_addr(env.img, &(env.bpp), &(env.size_line),
				&(env.endian));


	init_cam(&env.camera, 0, 0, 0);
	init_cam_angle(&env.camera, 0, 0);


	mlx_expose_hook(env.win, throw_view_plane, &env);
	mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env);
	// mlx_hook(env.win, KeyPress, KeyPressMask, keypress_hook, &env);
	// mlx_hook(env.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &env);
	mlx_loop_hook(env.mlx, throw_view_plane, &env);
	mlx_loop(env.mlx);

	return (0);
}
