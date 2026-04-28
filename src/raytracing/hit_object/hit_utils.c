/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:15:10 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/28 19:34:45 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void initialize_hit_structure(t_hit *hit)
{
    hit->t = 1e9;
    hit->point.x = 0.0;
    hit->point.y = 0.0;
    hit->point.z = 0.0;
    hit->normal.vx = 0.0;
    hit->normal.vy = 0.0;
    hit->normal.vz = 0.0;
    hit->color.r = 0.0;
    hit->color.g = 0.0;
    hit->color.b = 0.0;
    hit->is_hit = false;
}

t_point	ray_at(t_ray ray, double t)
{
	t_point	p;

	p.x = ray.origin.x + t * ray.dir.vx;
	p.y = ray.origin.y + t * ray.dir.vy;
	p.z = ray.origin.z + t * ray.dir.vz;
	return (p);
}

void update_closest_hit(t_hit *closest, t_hit hit)
{
    if (hit.is_hit && (!closest->is_hit || hit.t < closest->t))
			*closest = hit;
}

t_hit make_hit(t_ray ray, double t, t_vector normal, t_color color)
{
	t_hit hit;

	hit.is_hit = true;
	hit.t = t;
	hit.point = ray_at(ray, t);
	hit.normal = normal;
	hit.color = color;
	return(hit);
}
