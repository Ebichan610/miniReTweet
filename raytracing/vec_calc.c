/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:31:53 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/12 23:45:06 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector vec_add(t_vector a, t_vector b)
{
    t_vector v;

    v.vx = a.vx + b.vx;
    v.vy = a.vy + b.vy;
    v.vz = a.vz + b.vz;
    return(v);
}

t_vector vec_sub(t_vector a, t_vector b)
{
    t_vector v;

    v.vx = a.vx - b.vx;
    v.vy = a.vy - b.vy;
    v.vz = a.vz - b.vz;
    return(v);
}

t_vector vec_mul(t_vector v, double t)
{
    v.vx *= t;
    v.vy *= t;
    v.vz *= t;
    return(v);
}

double vec_dot(t_vector a, t_vector b)
{
    return(a.vx * b.vx + a.vy * b.vy + a.vz * b.vz);
}

t_vector vec_cross(t_vector a, t_vector b)
{
    t_vector v;

    v.vx = a.vy * b.vz - a.vz * b.vy;
    v.vy = a.vz * b.vx - a.vx * b.vz;
    v.vz = a.vx * b.vy - a.vy * b.vx;
    return(v);
}

t_vector vec_normalize(t_vector a)
{
    double len;

    len = sqrt(a.vx * a.vx + a.vy * a.vy + a.vz * a.vz);
    if(len < 1e-10)
        return(a);
    a.vx /= len;
    a.vy /= len;
    a.vz /= len;
    return(a);
}

t_vector	vec_sub_point(t_point a, t_point b)
{
	t_vector	v;

	v.vx = a.x - b.x;
	v.vy = a.y - b.y;
	v.vz = a.z - b.z;
	return (v);
}
