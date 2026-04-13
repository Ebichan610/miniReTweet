/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 22:08:55 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 01:10:09 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector get_plane_normal(t_ray ray, t_plane *plane)
{
    t_vector normal;

    normal = vec_normalize(plane->vector);
    if(vec_dot(ray.dir, normal) > 0)
        normal = vec_mul(normal, -1.0);
    return(normal);
}

t_hit hit_plane(t_ray ray, t_plane *plane)
{
    t_vector oc;
    double denom;
    double t;
    t_hit hit;
    
    hit.hit = false;
    denom = vec_dot(ray.dir, plane->vector);
    if(fabs(denom) < 1e-6)
        return(hit);
    oc = vec_sub_point(plane->point, ray.origin);
    t = vec_dot(oc, plane->vector) / denom;
    if(t < 1e-6)
        return(hit);
    hit.hit = true;
    hit.t = t;
    hit.point = ray_at(ray, t);
    hit.normal = get_plane_normal(ray, plane);
    hit.color = plane->color;
    return(hit);
}
