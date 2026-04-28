/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 01:32:42 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/28 18:20:15 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void check_spheres(t_hit *closest, t_ray ray, t_sphere *sphere)
{
    t_hit   hit;
    
    while(sphere)
    {
        hit = hit_sphere(ray, sphere);
        update_closest_hit(closest, hit);
        sphere = sphere->next;
    }
}

static void check_planes(t_hit *closest, t_ray ray, t_plane *plane)
{
    t_hit   hit;
    
    while(plane)
    {
        hit = hit_plane(ray, plane);
        update_closest_hit(closest, hit);
        plane = plane->next;
    }
}

static void check_cylinders(t_hit *closest, t_ray ray, t_cylinder *cylinder)
{
    t_hit   hit;
    
    while(cylinder)
    {
        hit = hit_cylinder(ray, cylinder);
        update_closest_hit(closest, hit);
        cylinder = cylinder->next;
    }
}

t_hit	hit_object(t_minirt *minirt, t_ray ray)
{
	t_hit		closest;
	
    initialize_hit_structure(&closest);
    check_spheres(&closest, ray, minirt->elem->sphere);
    check_planes(&closest, ray, minirt->elem->plane);
    check_cylinders(&closest, ray, minirt->elem->cylinder);
	return (closest);
}
