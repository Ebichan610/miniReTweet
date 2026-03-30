/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:46 by ebichan           #+#    #+#             */
/*   Updated: 2026/03/30 13:31:03 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	init_mlx(t_minirt *minirt)
{
	minirt->mlx_ptr = init_mlx();
	if (minirt->mlx_ptr == NULL)
		return (false);
	minirt->win_ptr = mlx_new_window(minirt->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"miniRT");
	if (minirt->win_ptr == NULL)
		return (false);
	minirt->img_ptr = mlx_new_image(minirt->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (minirt->img_ptr == NULL)
		return (false);
	minirt->addr = mlx_get_data_addr(minirt->img_ptr, &minirt->bits_per_pixel,
			&minirt->size_line, &minirt->endian);
	if (minirt->addr = NULL)
		return (false);
	return (true);
}

t_minirt	*init_minirt(char *filename)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)malloc(sizeof(t_minirt));
	if (minirt == NULL)
	{
		perror("Error\nmalloc");
		return (NULL);
	}
	ft_bzero(minirt, sizeof(minirt));
	minirt->elem = read_file(filename);
	if (minirt->elem == NULL)
	{
		(void)free_all(minirt);
		return (NULL);
	}
	if (init_mlx(minirt) == false)
	{
		(void)free_all(minirt);
		return (NULL);
	}
}
