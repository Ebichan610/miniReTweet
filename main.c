/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:46:21 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 18:32:38 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i < 3)
		return (false);
	if (str[i - 3] == '.' && str[i - 2] == 'r' && str[i - 1] == 't')
		return (true);
	return (false);
}

int	main(int argc, char *argv[])
{
	t_minirt	*minirt;

	if (argc != 2)
	{
		print_error("Invalid argument number\n");
		return (1);
	}
	if (check_arg(argv[1]) == false)
	{
		print_error("Invalid argument\n");
		return (1);
	}
	minirt = init_minirt(argv[1]);
	if (minirt == NULL)
		return (1);
	drawing_picture(minirt);
	mlx_put_image_to_window(minirt->mlx_ptr, minirt->win_ptr, minirt->img_ptr,
		0, 0);
	setup_hooks(minirt);
	mlx_loop(minirt->mlx_ptr);
	return (0);
}
