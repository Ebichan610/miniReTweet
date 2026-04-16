/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:14 by yebi              #+#    #+#             */
/*   Updated: 2026/04/16 12:36:53 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	hit_side(t_ray ray, t_cylinder *cylinder)
{
	t_vector	oc;
	t_vector	d_perp;
	t_vector	oc_perp;
	double		abc[3];
	double		disc;

	oc = vec_sub_point(ray.origin, cylinder->point);
	d_perp = vec_sub(ray.dir, vec_mul(cylinder->vector, vec_dot(ray.dir,
					cylinder->vector)));
	oc_perp = vec_sub(oc, vec_mul(cylinder->vector, vec_dot(oc,
					cylinder->vector)));
	abc[0] = vec_dot(d_perp, d_perp);
	abc[1] = 2.0 * vec_dot(d_perp, oc_perp);
	abc[2] = vec_dot(oc_perp, oc_perp) - cylinder->r * cylinder->r;
	disc = abc[1] * abc[1] - 4.0 * abc[0] * abc[2];
	if (disc < 0)
		return (-1.0);
	return (solve_quadratic(abc[0], abc[1], disc));
}

static bool	check_height(t_ray ray, t_cylinder *cylinder, double t)
{
	t_point		hit_point;
	t_vector	cp;
	double		h;

	hit_point = ray_at(ray, t);
	cp = vec_sub_point(hit_point, cylinder->point);
	h = vec_dot(cp, cylinder->vector);
	return (h >= 0 && h <= cylinder->h);
}

static double	hit_cap(t_ray ray, t_cylinder *cylinder, bool bottom)
{
	t_plane		cap;
	t_hit		hit;
	t_vector	cp;
	double		dist2;

	if (bottom)
		cap.point = cylinder->point;
	else
	{
		cap.point.x = cylinder->point.x + cylinder->vector.vx * cylinder->h;
		cap.point.y = cylinder->point.y + cylinder->vector.vy * cylinder->h;
		cap.point.z = cylinder->point.z + cylinder->vector.vz * cylinder->h;
	}
	cap.vector = cylinder->vector;
	hit = hit_plane(ray, &cap);
	if (!hit.hit)
		return (-1.0);
	cp = vec_sub_point(hit.point, cap.point);
	dist2 = vec_dot(cp, cp);
	if (dist2 > cylinder->r * cylinder->r)
		return (-1.0);
	return (hit.t);
}

static t_vector	get_side_normal(t_point hit_point, t_cylinder *cylinder)
{
	t_vector	cp;
	t_vector	proj;

	cp = vec_sub_point(hit_point, cylinder->point);
	proj = vec_mul(cylinder->vector, vec_dot(cp, cylinder->vector));
	return (vec_normalize(vec_sub(cp, proj)));
}

static t_vector get_cap_normal(t_ray ray, t_cylinder *cylinder)
{
	t_vector normal;

	normal = vec_normalize(cylinder->vector);
	if(vec_dot(ray.dir, normal) > 0)
		normal = vec_mul(normal, -1.0);
	return(normal);
}

static double	get_best_cap(t_ray ray, t_cylinder *cylinder)
{
	double	tb;
	double	tt;

	tb = hit_cap(ray, cylinder, true);
	tt = hit_cap(ray, cylinder, false);
	if (tb > 1e-6 && (tt < 1e-6 || tb < tt))
		return (tb);
	if (tt > 1e-6)
		return (tt);
	return (-1.0);
}

static t_hit	make_hit(t_ray ray, t_color color, double t, t_vector normal)
{
	t_hit	hit;

	hit.hit = true;
	hit.t = t;
	hit.point = ray_at(ray, t);
	hit.normal = vec_normalize(normal);
	hit.color = color;
	return (hit);
}

t_hit	hit_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_hit	hit;
	double	side;
	double	cap;

	hit.hit = false;
	side = hit_side(ray, cylinder);
	if (side > 1e-6 && check_height(ray, cylinder, side))
		hit = make_hit(ray, cylinder->color, side, get_side_normal(ray_at(ray,
						side), cylinder));
	cap = get_best_cap(ray, cylinder);
	if (cap > 1e-6 && (!hit.hit || cap < hit.t))
		hit = make_hit(ray, cylinder->color, cap, get_cap_normal(ray, cylinder));
	return (hit);
}
