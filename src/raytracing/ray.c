/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:32:12 by yebi              #+#    #+#             */
/*   Updated: 2026/04/13 18:32:13 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_camera_axes(t_camera *camera, t_vector *right, t_vector *up)
{
	t_vector	forward;
	t_vector	world_up;

	forward = vec_normalize(camera->vector);
	world_up = (t_vector){0, 1, 0};
	if (fabs(vec_dot(forward, world_up)) > 0.999)
		world_up = (t_vector){0, 0, 1};
	*right = vec_normalize(vec_cross(forward, world_up));
	*up = vec_cross(*right, forward);
}

double	x_pixel_normalize(t_camera *camera, int x)
{
	double	aspect;
	double	scale;
	double	u;

	aspect = (double)WIN_WIDTH / WIN_HEIGHT;
	scale = tan(camera->fov / 2.0 * M_PI / 180.0);
	u = (2.0 * (x + 0.5) / WIN_WIDTH - 1.0) * aspect * scale;
	return (u);
}

double	y_pixel_normalize(t_camera *camera, int y)
{
	double	scale;
	double	v;

	scale = tan(camera->fov / 2.0 * M_PI / 180.0);
	v = (1.0 - 2.0 * (y + 0.5) / WIN_HEIGHT) * scale;
	return (v);
}

t_vector	get_ray_dir(t_camera *camera, t_vector u_right, t_vector v_up)
{
	t_vector	dir;
	t_vector	forward;

	forward = vec_normalize(camera->vector);
	dir = vec_add(vec_add(u_right, v_up), forward);
	return (vec_normalize(dir));
}

t_ray	create_ray(t_minirt *minirt, int x, int y)
{
	t_vector	right;
	t_vector	up;
	t_ray		ray;
	double		u;
	double		v;

	get_camera_axes(minirt->elem->camera, &right, &up);
	u = x_pixel_normalize(minirt->elem->camera, x);
	v = y_pixel_normalize(minirt->elem->camera, y);
	ray.origin = minirt->elem->camera->point;
	ray.dir = get_ray_dir(minirt->elem->camera, vec_mul(right, u), vec_mul(up,
				v));
	return (ray);
}
