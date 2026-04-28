/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_side.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:41:01 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/28 19:54:50 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_height(t_ray ray, t_cylinder *cylinder, double t)
{
	t_point		hit_point;
	t_vector	cp;
	double		h;

	hit_point = ray_at(ray, t);
	cp = vec_sub_point(hit_point, cylinder->point);
	h = vec_dot(cp, cylinder->vector);
	return (h >= -cylinder->h / 2.0 && h <= cylinder->h / 2.0);
}

static t_quad calc_cylinder_quad(t_ray ray, t_cylinder *cylinder)
{
    t_quad quad;
    t_vector oc;
    t_vector d_perp;
    t_vector oc_perp;

    oc = vec_sub_point(ray.origin, cylinder->point);
    d_perp = vec_sub(ray.dir, vec_mul(cylinder->vector, vec_dot(ray.dir, cylinder->vector)));
    oc_perp = vec_sub(oc, vec_mul(cylinder->vector, vec_dot(oc, cylinder->vector)));
    quad.a = vec_dot(d_perp, d_perp);
    quad.b = 2.0 *  vec_dot(d_perp, oc_perp);
    quad.c = vec_dot(oc_perp, oc_perp) - cylinder->r * cylinder->r;
    quad.disc = quad.b * quad.b - 4.0 * quad.a * quad.c;
    return(quad);
}

static double solve_side_t(t_ray ray, t_cylinder *cylinder, t_quad quad)
{
    double t1;
    double t2;
    double sqrt_disc;
    double t_min;

    sqrt_disc = sqrt(quad.disc);
	t1 = (-quad.b - sqrt_disc) / (2.0 * quad.a);
	t2 = (-quad.b + sqrt_disc) / (2.0 * quad.a);
    t_min = 1e9;
	if (t1 > EPSILON && check_height(ray, cylinder, t1))
		t_min = t1;
	if (t2 > EPSILON && check_height(ray, cylinder, t2) && t2 < t_min)
		t_min = t2;
    if(t_min >= 1e9)
	    return (-1.0);
    return(t_min);
}

double hit_side(t_ray ray, t_cylinder *cylinder)
{
    t_quad quad;

    quad = calc_cylinder_quad(ray, cylinder);
    if(quad.a < EPSILON || quad.disc < 0.0)
        return(-1.0);
    return(solve_side_t(ray, cylinder, quad));
}
