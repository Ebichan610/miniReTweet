/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:25:07 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/03 17:28:24 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void print_error(char *s)
{
    ft_putstr_fd("Error\n", STDERR_FILENO);
    ft_putstr_fd(s, STDERR_FILENO);
}
