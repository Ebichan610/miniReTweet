/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:25:07 by ebichan           #+#    #+#             */
/*   Updated: 2026/03/30 13:30:33 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(char *s)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
}
