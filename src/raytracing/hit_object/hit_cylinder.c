/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:14 by yebi              #+#    #+#             */
/*   Updated: 2026/04/24 01:36:45 by ebichan          ###   ########.fr       */
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
	return (h >= 0 && h <= cylinder->h);
}



static double	hit_side(t_ray ray, t_cylinder *cylinder)
{
	t_vector	oc;
	t_vector	d_perp;
	t_vector	oc_perp;
	double		abc[3];
	double		disc;
	double		t1;
	double		t2;

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
	t1 = (-abc[1] - sqrt(disc)) / (2.0 * abc[0]);
	t2 = (-abc[1] + sqrt(disc)) / (2.0 * abc[0]);
	// t1が有効なら必ずt1を返す（外側の交点）
	if (t1 > 1e-6 && check_height(ray, cylinder, t1))
        return (t1);
    // t2はt1が負（レイ原点が円柱内部）の場合のみ返す
    if (t1 <= 1e-6 && t2 > 1e-6 && check_height(ray, cylinder, t2))
        return (t2);
    return (-1.0);
}

static double	hit_cap(t_ray ray, t_cylinder *cylinder, bool bottom)
{
	t_point		cap_center;
	t_vector	to_cap;
	double		denom;
	double		t;
	t_vector	cp;

	if (bottom)
		cap_center = cylinder->point;
	else
	{
		cap_center.x = cylinder->point.x + cylinder->vector.vx * cylinder->h;
		cap_center.y = cylinder->point.y + cylinder->vector.vy * cylinder->h;
		cap_center.z = cylinder->point.z + cylinder->vector.vz * cylinder->h;
	}
	denom = vec_dot(ray.dir, cylinder->vector);
	if (fabs(denom) < EPSILON)
		return (-1.0);
	to_cap = vec_sub_point(cap_center, ray.origin);
	t = vec_dot(to_cap, cylinder->vector) / denom;
	if (t < 1e-6)
		return (-1.0);
	cp = vec_sub_point(ray_at(ray, t), cap_center);
	if (vec_dot(cp, cp) > cylinder->r * cylinder->r)
		return (-1.0);
	return (t);
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

t_hit	hit_cylinder(t_ray ray, t_cylinder *cylinder)
{
    t_hit   hit;
    double  t;
    // bool    hit_body;

    hit.hit = false;
    hit.t = 1e9;

    // side判定：hit.tを閾値として使う
    t = hit_side(ray, cylinder);
    if (t > EPSILON && t < hit.t)
    {
        hit.hit = true;
        hit.t = t;
        hit.point = ray_at(ray, t);
        hit.normal = get_side_normal(hit.point, cylinder);
        hit.color = cylinder->color;
        // hit_body = true;
    }

    // cap判定：hit.tより近い場合だけ上書き
    t = hit_cap(ray, cylinder, true);
    if (t > EPSILON && t < hit.t)
    {
        hit.hit = true;
        hit.t = t;
        hit.point = ray_at(ray, t);
        hit.normal = get_cap_normal(ray, cylinder);
        hit.color = cylinder->color;
    }
    t = hit_cap(ray, cylinder, false);
    if (t > EPSILON && t < hit.t)
    {
        hit.hit = true;
        hit.t = t;
        hit.point = ray_at(ray, t);
        hit.normal = get_cap_normal(ray, cylinder);
        hit.color = cylinder->color;
    }
    return (hit);
}
