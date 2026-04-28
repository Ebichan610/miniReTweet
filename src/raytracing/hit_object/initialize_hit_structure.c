/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hit_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:57:29 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/28 17:19:22 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void initialize_hit_structure(t_hit *hit)
{
    hit->t = 1e9;
    hit->point.x = 0.0;
    hit->point.y = 0.0;
    hit->point.z = 0.0;
    hit->normal.vx = 0.0;
    hit->normal.vy = 0.0;
    hit->normal.vz = 0.0;
    hit->color.r = 0.0;
    hit->color.g = 0.0;
    hit->color.b = 0.0;
    hit->is_hit = false;
}
