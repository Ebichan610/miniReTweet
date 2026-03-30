/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:05:33 by ebichan           #+#    #+#             */
/*   Updated: 2026/03/30 13:31:12 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	key_hook(int keycode, t_minirt *minirt)
{
	if (keycode == KEY_ESC)
		free_all(minirt);
	return (0);
}

void	setup_hooks(t_minirt *minirt)
{
	mlx_key_hook(minirt->win_ptr, key_hook, minirt);
	mlx_hook(minirt->win_ptr, EVENT_DESTROY_NOTIFY, 0, free_all, minirt);
}
