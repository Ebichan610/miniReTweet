/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_picture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:58 by yebi              #+#    #+#             */
/*   Updated: 2026/04/27 01:32:30 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_pixel_put(t_minirt *minirt, int x, int y, int color)
{
	char	*dst;

	dst = minirt->addr + (y * minirt->size_line + x * (minirt->bits_per_pixel
				/ 8));
	*(unsigned int *)dst = color;
}

void	drawing_picture(t_minirt *minirt)
{
	t_ray	ray;
	t_hit	hit;
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = create_ray(minirt, x, y);
			hit = hit_object(minirt, ray);
			if (hit.hit)
				my_pixel_put(minirt, x, y, color_to_int(calc_lighting(minirt,
							hit)));
			else
				my_pixel_put(minirt, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
