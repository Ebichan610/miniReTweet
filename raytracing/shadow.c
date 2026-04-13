/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:05:45 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 00:54:00 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray make_shadow_ray(t_hit hit, t_point light_pos)
{
    t_ray shadow_ray;
    t_vector bias;

    bias = vec_mul(hit.normal, 0.001);
    shadow_ray.origin.x = hit.point.x + bias.vx;
    shadow_ray.origin.y = hit.point.y + bias.vy;
    shadow_ray.origin.z = hit.point.z + bias.vz;
    shadow_ray.dir = vec_normalize(vec_sub_point(light_pos, shadow_ray.origin));
    return(shadow_ray);
}

static double light_distance(t_ray shadow_ray, t_point light_pos)
{
    t_vector to_light;

    to_light = vec_sub_point(light_pos, shadow_ray.origin);
    return(sqrt(vec_dot(to_light, to_light)));
}

static bool shadow_sphere(t_ray shadow_ray, t_sphere *sphere, double distance)
{
    t_hit hit;

    while(sphere)
    {
        hit = hit_sphere(shadow_ray, sphere);
        if(hit.hit && hit.t < distance)
            return(true);
        sphere = sphere->next;
    }
    return(false);
}

static bool shadow_plane(t_ray shadow_ray, t_plane *plane, double distance)
{
    t_hit hit;

    while(plane)
    {
        hit = hit_plane(shadow_ray, plane);
        if(hit.hit && hit.t < distance)
            return(true);
        plane = plane->next;
    }
    return(false);
}

static bool shadow_cylinder(t_ray shadow_ray, t_cylinder *cylinder, double distance)
{
    t_hit hit;

    while(cylinder)
    {
        hit = hit_cylinder(shadow_ray, cylinder);
        if(hit.hit && hit.t < distance)
            return(true);
        cylinder = cylinder->next;
    }
    return(false);
}

bool is_in_shadow(t_minirt *minirt, t_hit hit)
{
    t_ray shadow_ray;
    double distance;

    shadow_ray = make_shadow_ray(hit, minirt->elem->light->point);
    distance = light_distance(shadow_ray, minirt->elem->light->point);
    if(shadow_sphere(shadow_ray, minirt->elem->sphere, distance))
        return(true);
    if(shadow_plane(shadow_ray, minirt->elem->plane, distance))
        return(true);
    if(shadow_cylinder(shadow_ray, minirt->elem->cylinder, distance))
        return(true);
    return(false);
}
