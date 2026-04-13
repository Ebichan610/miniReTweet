/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:31:50 by yebi              #+#    #+#             */
/*   Updated: 2026/04/13 18:31:51 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_add(t_color a, t_color b)
{
	a.r += b.r;
	a.g += b.g;
	a.b += b.b;
	return (a);
}

t_color	color_mul(t_color c, double t)
{
	c.r *= t;
	c.g *= t;
	c.b *= t;
	return (c);
}

t_color	color_mul_color(t_color a, t_color b)
{
	a.r *= b.r;
	a.g *= b.g;
	a.b *= b.b;
	return (a);
}

int	color_to_int(t_color c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fmax(0.0, fmin(c.r, 1.0)) * 255.0);
	g = (int)(fmax(0.0, fmin(c.g, 1.0)) * 255.0);
	b = (int)(fmax(0.0, fmin(c.b, 1.0)) * 255.0);
	return (r << 16 | g << 8 | b);
}
