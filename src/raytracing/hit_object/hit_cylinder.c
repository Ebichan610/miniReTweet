/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:14 by yebi              #+#    #+#             */
/*   Updated: 2026/04/28 19:35:38 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector get_side_normal(t_point hit_point, t_cylinder *cylinder)
{
    t_vector cp;
    t_vector proj;

    cp = vec_sub_point(hit_point, cylinder->point);
    proj = vec_mul(cylinder->vector, vec_dot(cp, cylinder->vector));
    return(vec_normalize(vec_sub(cp, proj)));
}

static t_vector get_cap_normal(t_ray ray, t_cylinder *cylinder, bool top)
{
    t_vector normal;
    
    if(top)
        normal = cylinder->vector;
    else
        normal = vec_mul(cylinder->vector, -1.0);
    if(vec_dot(ray.dir, normal) > 0)
        normal = vec_mul(normal, -1.0);
    return(vec_normalize(normal));
}

static void check_side(t_ray ray, t_cylinder *cylinder, t_hit *hit)
{
	double t;
	t_vector normal;

	t = hit_side(ray, cylinder);
	if(t > EPSILON && t < hit->t)
	{
		normal = get_side_normal(ray_at(ray, t), cylinder);
		*hit = make_hit(ray, t, normal, cylinder->color);
	}
}

static void check_cap(t_ray ray, t_cylinder * cylinder, t_hit *hit, bool top)
{
	double t;
	t_vector normal;
	
	t = hit_cap(ray, cylinder, top);
	if(t > EPSILON && t < hit->t)
	{
		normal = get_cap_normal(ray, cylinder, top);
		*hit = make_hit(ray, t, normal, cylinder->color);
	}
}

t_hit	hit_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_hit	hit;

	initialize_hit_structure(&hit);
	check_side(ray, cylinder, &hit);
	check_cap(ray, cylinder, &hit, false);
	check_cap(ray, cylinder, &hit, true);
	return (hit);
}
