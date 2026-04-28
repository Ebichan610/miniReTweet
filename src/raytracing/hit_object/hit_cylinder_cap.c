/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_cap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 18:41:17 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/28 19:35:29 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_point get_cap_center(t_cylinder *cylinder, bool top)
{
    t_vector half;

    half = vec_mul(cylinder->vector, cylinder->h/2.0);
    if(top)
        return(vec_add_point(cylinder->point, half));
    return(vec_sub_point_vec(cylinder->point, half));
}

static double calc_cap_t(t_ray ray, t_cylinder *cylinder, t_point cap_center)
{
    t_vector to_cap;
    t_vector cp;
    double denom;
    double t;

    denom = vec_dot(ray.dir, cylinder->vector);
    if(fabs(denom) < EPSILON)
        return(-1.0);
    to_cap = vec_sub_point(cap_center, ray.origin);
    t = vec_dot(to_cap, cylinder->vector) / denom;
    if(t < EPSILON)
        return(-1.0);
    cp = vec_sub_point(ray_at(ray, t), cap_center);
    if(vec_dot(cp, cp) > cylinder->r * cylinder->r)
        return(-1.0);
    return(t);
}

double hit_cap(t_ray ray, t_cylinder *cylinder, bool top)
{
    t_point cap_center;

    cap_center = get_cap_center(cylinder, top);
    return(calc_cap_t(ray, cylinder, cap_center));
}
