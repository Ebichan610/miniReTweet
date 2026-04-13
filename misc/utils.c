/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:23:48 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 18:30:40 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	count_str(char **strs)
{
	size_t	result;

	result = 0;
	if (strs == NULL)
		return (-1);
	while (*strs != NULL)
	{
		result++;
		strs++;
	}
	return (result);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	check_positive_int_num(char *str)
{
	long	result;

	result = 0;
	if (str == NULL || *str == '\0')
		return (false);
	while (*str >= '0' && *str <= '9')
	{
		if (*str < '0' || *str > '9')
			return (false);
		if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (*str
					- '0') > INT_MAX % 10))
			return (false);
		result = result * 10 + (long)(*str - '0');
		str++;
	}
	return (true);
}

bool	is_zero_vector(t_vector vector)
{
	if (vector.vx == 0 && vector.vy == 0 && vector.vz == 0)
		return (true);
	return (false);
}