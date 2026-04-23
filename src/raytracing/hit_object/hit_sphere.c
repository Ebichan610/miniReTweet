/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:37 by yebi              #+#    #+#             */
/*   Updated: 2026/04/23 14:54:44 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	solve_quadratic(double a, double b, double disc)
{
	double	t1;
	double	t2;

	t1 = (-b - sqrt(disc)) / (2.0 * a);
	t2 = (-b + sqrt(disc)) / (2.0 * a);
	if (t1 > EPSILON)
		return (t1);
	if (t2 > EPSILON)
		return (t2);
	return (-1.0);
}

t_point	ray_at(t_ray ray, double t)
{
	t_point	p;

	p.x = ray.origin.x + t * ray.dir.vx;
	p.y = ray.origin.y + t * ray.dir.vy;
	p.z = ray.origin.z + t * ray.dir.vz;
	return (p);
}

t_vector	get_sphere_normal(t_point hit_point, t_sphere *sphere)
{
	t_vector	normal;

	normal.vx = hit_point.x - sphere->point.x;
	normal.vy = hit_point.y - sphere->point.y;
	normal.vz = hit_point.z - sphere->point.z;
	return (vec_normalize(normal));
}

t_hit	hit_sphere(t_ray ray, t_sphere *sphere)
{
	t_vector	oc;
	double		a;
	double		b;
	double		disc;
	t_hit		hit;

	hit.hit = false;
	oc = vec_sub_point(ray.origin, sphere->point);
	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(oc, ray.dir);
	disc = b * b - 4.0 * a * (vec_dot(oc, oc) - sphere->r * sphere->r);
	if (disc < 0)
		return (hit);
	hit.t = solve_quadratic(a, b, disc);
	if (hit.t < 0)
		return (hit);
	hit.hit = true;
	hit.point = ray_at(ray, hit.t);
	hit.normal = get_sphere_normal(hit.point, sphere);
	hit.color = sphere->color;
	return (hit);
}
