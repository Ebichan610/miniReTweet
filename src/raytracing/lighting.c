/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:32:04 by yebi              #+#    #+#             */
/*   Updated: 2026/04/13 18:32:05 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	calc_ambient(t_elem *elem, t_color obj_color)
{
	t_color	amb_color;

	amb_color = color_mul_color(elem->amb->color, obj_color);
	return (color_mul(amb_color, elem->amb->ratio));
}

static t_color	calc_diffuse(t_elem *elem, t_hit hit)
{
	t_vector	light_dir;
	t_color		diff_color;
	double		bright;

	light_dir = vec_normalize(vec_sub_point(elem->light->point, hit.point));
	bright = vec_dot(hit.normal, light_dir);
	if (bright < 0.0)
		bright = 0.0;
	bright *= elem->light->ratio;
	diff_color = color_mul_color(elem->light->color, hit.color);
	return (color_mul(diff_color, bright));
}

t_color	calc_lighting(t_minirt *minirt, t_hit hit)
{
	t_color	ambient;
	t_color	diffuse;

	ambient = calc_ambient(minirt->elem, hit.color);
	if (is_in_shadow(minirt, hit))
		return (ambient);
	diffuse = calc_diffuse(minirt->elem, hit);
	return (color_add(ambient, diffuse));
}
