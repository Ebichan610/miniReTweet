/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 01:32:42 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/28 17:21:13 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	hit_object(t_minirt *minirt, t_ray ray)
{
	t_hit		closest;
	t_hit		hit;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	initialize_hit_structure(&closest);
	sphere = minirt->elem->sphere;
	while (sphere)
	{
		hit = hit_sphere(ray, sphere);
		if (hit.is_hit && (!closest.is_hit || hit.t < closest.t))
			closest = hit;
		sphere = sphere->next;
	}
	plane = minirt->elem->plane;
	while (plane)
	{
		hit = hit_plane(ray, plane);
		if (hit.is_hit && (!closest.is_hit || hit.t < closest.t))
			closest = hit;
		plane = plane->next;
	}
	cylinder = minirt->elem->cylinder;
	while (cylinder)
	{
		hit = hit_cylinder(ray, cylinder);
		if (hit.is_hit && (!closest.is_hit || hit.t < closest.t))
			closest = hit;
		cylinder = cylinder->next;
	}
	return (closest);
}
