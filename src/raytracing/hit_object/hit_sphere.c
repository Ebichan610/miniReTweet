/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:37 by yebi              #+#    #+#             */
/*   Updated: 2026/04/28 20:03:03 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_quad calc_sphere_quad(t_ray ray, t_sphere *sphere)
{
	t_quad quad;
	t_vector oc;

	oc = vec_sub_point(ray.origin, sphere->point);
	quad.a = vec_dot(ray.dir, ray.dir);
	quad.b = 2.0 * vec_dot(oc, ray.dir);
	quad.c =vec_dot(oc, oc) - sphere->r * sphere->r;
	quad.disc = quad.b * quad.b - 4.0 * quad.a * quad.c;
	return(quad);
}

static t_vector	get_sphere_normal(t_point hit_point, t_sphere *sphere)
{
	t_vector	normal;

	normal.vx = hit_point.x - sphere->point.x;
	normal.vy = hit_point.y - sphere->point.y;
	normal.vz = hit_point.z - sphere->point.z;
	return (vec_normalize(normal));
}

double	solve_quadratic(t_quad quad)
{
	double	t1;
	double	t2;
	double sqrt_disc;
	double t_min;
	
	sqrt_disc = sqrt(quad.disc);
	t1 = (-quad.b - sqrt_disc) / (2.0 * quad.a);
	t2 = (-quad.b + sqrt_disc) / (2.0 * quad.a);
	t_min = -1.0;
	if(t1 > EPSILON)
		t_min = t1;
	if (t2 > EPSILON)
	{
		if(t_min < 0 || t2 < t_min)
			t_min = t2;
	}
	return (t_min);
}

t_hit	hit_sphere(t_ray ray, t_sphere *sphere)
{
	t_hit		hit;
	t_quad		quad;

	initialize_hit_structure(&hit);
	quad = calc_sphere_quad(ray, sphere);
	if (quad.disc < 0)
		return (hit);
	hit.t = solve_quadratic(quad);
	if (hit.t < 0)
		return (hit);
	hit.is_hit = true;
	hit.point = ray_at(ray, hit.t);
	hit.normal = get_sphere_normal(hit.point, sphere);
	hit.color = sphere->color;
	return (hit);
}
