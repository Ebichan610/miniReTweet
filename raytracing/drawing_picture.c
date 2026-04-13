/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_picture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:58 by yebi              #+#    #+#             */
/*   Updated: 2026/04/13 18:31:58 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_pixel_put(t_minirt *minirt, int x, int y, int color)
{
	char	*dst;

	dst = minirt->addr + (y * minirt->size_line + x * (minirt->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

static t_hit	find_closest_hit(t_minirt *minirt, t_ray ray)
{
	t_hit		closest;
	t_hit		hit;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	closest.hit = false;
	closest.t = 1e9;
	sphere = minirt->elem->sphere;
	while (sphere)
	{
		hit = hit_sphere(ray, sphere);
		if (hit.hit && (!closest.hit || hit.t < closest.t))
			closest = hit;
		sphere = sphere->next;
	}
	plane = minirt->elem->plane;
	while (plane)
	{
		hit = hit_plane(ray, plane);
		if (hit.hit && (!closest.hit || hit.t < closest.t))
			closest = hit;
		plane = plane->next;
	}
	cylinder = minirt->elem->cylinder;
	while (cylinder)
	{
		hit = hit_cylinder(ray, cylinder);
		if (hit.hit && (!closest.hit || hit.t < closest.t))
			closest = hit;
		cylinder = cylinder->next;
	}
	return (closest);
}

void	drawing_picture(t_minirt *minirt)
{
	t_ray	ray;
	t_hit	hit;
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = create_ray(minirt, x, y);
			hit = find_closest_hit(minirt, ray);
			if (hit.hit)
				my_pixel_put(minirt, x, y, color_to_int(calc_lighting(minirt,
							hit)));
			else
				my_pixel_put(minirt, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
