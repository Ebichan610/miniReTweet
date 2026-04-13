/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:52:21 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 18:29:54 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	free_all(t_minirt *minirt)
{
	if (minirt == NULL)
		return (0);
	if (minirt->img_ptr != NULL)
		mlx_destroy_image(minirt->mlx_ptr, minirt->img_ptr);
	if (minirt->win_ptr != NULL)
		mlx_destroy_window(minirt->mlx_ptr, minirt->win_ptr);
	if (minirt->mlx_ptr != NULL)
	{
		// mlx_destroy_display(minirt->mlx_ptr);//Linux
		free(minirt->mlx_ptr);
	}
	if (minirt->elem != NULL)
		free_elem(minirt->elem);
	free(minirt);
	exit(EXIT_SUCCESS);
	return (0);
}
