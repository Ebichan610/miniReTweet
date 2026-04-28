/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:14 by yebi              #+#    #+#             */
/*   Updated: 2026/04/27 01:47:38 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** 高さチェック（cylinder->point を中心として ±h/2 の範囲）
*/
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

/*
** 側面の交差判定
** t1・t2両方をチェックし、有効な最近傍を返す
*/
static double	hit_side(t_ray ray, t_cylinder *cylinder)
{
	t_vector	oc;
	t_vector	d_perp;
	t_vector	oc_perp;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		t1;
	double		t2;
	double		t_min;

	oc = vec_sub_point(ray.origin, cylinder->point);

	d_perp = vec_sub(ray.dir,
			vec_mul(cylinder->vector, vec_dot(ray.dir, cylinder->vector)));

	oc_perp = vec_sub(oc,
			vec_mul(cylinder->vector, vec_dot(oc, cylinder->vector)));

	a = vec_dot(d_perp, d_perp);
	if (a < EPSILON)
		return (-1.0);

	b = 2.0 * vec_dot(d_perp, oc_perp);
	c = vec_dot(oc_perp, oc_perp) - cylinder->r * cylinder->r;

	disc = b * b - 4.0 * a * c;
	if (disc < 0.0)
		return (-1.0);

	t1 = (-b - sqrt(disc)) / (2.0 * a);
	t2 = (-b + sqrt(disc)) / (2.0 * a);

	t_min = 1e9;
	if (t1 > EPSILON && check_height(ray, cylinder, t1))
		t_min = t1;
	if (t2 > EPSILON && check_height(ray, cylinder, t2) && t2 < t_min)
		t_min = t2;

	if (t_min >= 1e9)
		return (-1.0);

	return (t_min);
}

/*
** キャップ（円盤）との交差
** top=true  → 上面（中心 + h/2 方向）
** top=false → 下面（中心 - h/2 方向）
*/
static double	hit_cap(t_ray ray, t_cylinder *cylinder, bool top)
{
	t_point		cap_center;
	t_vector	half;
	t_vector	to_cap;
	t_vector	cp;
	double		denom;
	double		t;

	half = vec_mul(cylinder->vector, cylinder->h / 2.0);
	if (top)
		cap_center = vec_add_point(cylinder->point, half);
	else
		cap_center = vec_sub_point_vec(cylinder->point, half);
	denom = vec_dot(ray.dir, cylinder->vector);
	if (fabs(denom) < EPSILON)
		return (-1.0);
	to_cap = vec_sub_point(cap_center, ray.origin);
	t = vec_dot(to_cap, cylinder->vector) / denom;
	if (t < EPSILON)
		return (-1.0);
	cp = vec_sub_point(ray_at(ray, t), cap_center);
	if (vec_dot(cp, cp) > cylinder->r * cylinder->r)
		return (-1.0);
	return (t);
}

/*
** 側面の法線
** 軸方向成分を除いた外向きベクトル
*/
static t_vector	get_side_normal(t_point hit_point, t_cylinder *cylinder)
{
	t_vector	cp;
	t_vector	proj;

	cp = vec_sub_point(hit_point, cylinder->point);
	proj = vec_mul(cylinder->vector, vec_dot(cp, cylinder->vector));
	return (vec_normalize(vec_sub(cp, proj)));
}

/*
** キャップの法線
** top=true  → 軸方向（上向き）
** top=false → 軸と逆方向（下向き）
** レイと同じ向きなら反転（両面対応）
*/
static t_vector	get_cap_normal(t_ray ray, t_cylinder *cylinder, bool top)
{
	t_vector	normal;

	if (top)
		normal = cylinder->vector;
	else
		normal = vec_mul(cylinder->vector, -1.0);
	if (vec_dot(ray.dir, normal) > 0)
		normal = vec_mul(normal, -1.0);
	return (vec_normalize(normal));
}

/*
** 円柱との交差判定メイン
** 側面→下面→上面の順に判定し、最も近いtを採用する
*/
t_hit	hit_cylinder(t_ray ray, t_cylinder *cylinder)
{
	t_hit	hit;
	double	t;

	hit.hit = false;
	hit.t = 1e9;
	t = hit_side(ray, cylinder);
	if (t > EPSILON && t < hit.t)
	{
		hit.hit = true;
		hit.t = t;
		hit.point = ray_at(ray, t);
		hit.normal = get_side_normal(hit.point, cylinder);
		hit.color = cylinder->color;
	}
	t = hit_cap(ray, cylinder, false);
	if (t > EPSILON && t < hit.t)
	{
		hit.hit = true;
		hit.t = t;
		hit.point = ray_at(ray, t);
		hit.normal = get_cap_normal(ray, cylinder, false);
		hit.color = cylinder->color;
	}
	t = hit_cap(ray, cylinder, true);
	if (t > EPSILON && t < hit.t)
	{
		hit.hit = true;
		hit.t = t;
		hit.point = ray_at(ray, t);
		hit.normal = get_cap_normal(ray, cylinder, true);
		hit.color = cylinder->color;
	}
	return (hit);
}
