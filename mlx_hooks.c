/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:05:33 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/24 16:11:34 by ebichan          ###   ########.fr       */
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
