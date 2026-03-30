/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:43:56 by ebichan           #+#    #+#             */
/*   Updated: 2026/03/30 13:29:29 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	apply_point(char *str)
{
	t_point	point;
	char	**strs;

	point.x = NaN;
	point.y = NaN;
	point.z = NaN;
	strs = ft_split(str, ',');
	if (strs == NULL)
		return (point);
	if (count_str(strs) != 3)
	{
		free_strs(strs);
		return (point);
	}
	if (!in_double_range(strs[0], DOUBLE_ALL) || !in_double_range(strs[0],
			DOUBLE_ALL) || !in_double_range(strs[0], DOUBLE_ALL))
	{
		free_strs(strs);
		return (point);
	}
	point.x = ft_atof(strs[0]);
	point.y = ft_atof(strs[1]);
	point.z = ft_atof(strs[2]);
	free_strs(strs);
	return (point);
}

t_vector	apply_vector(char *str)
{
	t_vector	vector;
	char		**strs;

	vector.vx = NaN;
	vector.vy = NaN;
	vector.vz = NaN;
	strs = ft_split(str, ',');
	if (strs == NULL)
		return (vector);
	if (count_str(strs) != 3)
	{
		free_strs(strs);
		return (vector);
	}
	if (!in_vector_range(strs[0]) || !in_vector_range(strs[0])
		|| !in_vector_range(strs[0]))
	{
		free_strs(strs);
		return (vector);
	}
	vector.vx = ft_atof(strs[0]);
	vector.vy = ft_atof(strs[1]);
	vector.vz = ft_atof(strs[2]);
	free_strs(strs);
	return (vector);
}

t_color	apply_color(char *str)
{
	t_color	color;
	char	**strs;

	color.r = -1;
	color.g = -1;
	color.b = -1;
	strs = ft_split(str, ',');
	if (strs == NULL)
		return (color);
	if (count_str(strs) != 3)
	{
		free_strs(strs);
		return (color);
	}
	if (!in_color_range(strs[0]) || !in_color_range(strs[1])
		|| !in_color_range(strs[2]))
	{
		free_strs(strs);
		return (color);
	}
	color.r = (double)ft_atoi(strs[0]);
	color.g = (double)ft_atoi(strs[1]);
	color.b = (double)ft_atoi(strs[2]);
	free_strs(strs);
	return (color);
}
