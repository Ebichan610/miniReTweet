/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:05:33 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 18:32:51 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	key_hook(int keycode, t_minirt *minirt)
{
	if (keycode == XK_Escape)
		free_all(minirt);
	return (0);
}

void	setup_hooks(t_minirt *minirt)
{
	mlx_key_hook(minirt->win_ptr, key_hook, minirt);
	mlx_hook(minirt->win_ptr, DestroyNotify, KeyPressMask, free_all, minirt);
}
