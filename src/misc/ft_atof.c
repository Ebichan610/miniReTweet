/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:09:37 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 18:30:33 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	calc_integer_part(const char **nptr)
{
	double	result;

	result = 0;
	if (**nptr < '0' || **nptr > '9')
		return (NAN);
	while (**nptr >= '0' && **nptr <= '9')
	{
		result = result * 10 + **nptr - '0';
		(*nptr)++;
		if (isinf(result))
			return (INFINITY);
	}
	return (result);
}

static double	calc_decimal_part(const char **nptr)
{
	double	result;
	double	factor;

	result = 0;
	factor = 0.1;
	(*nptr)++;
	if (**nptr < '0' || **nptr > '9')
		return (INFINITY);
	while (**nptr >= '0' && **nptr <= '9')
	{
		result += (**nptr - '0') * factor;
		(*nptr)++;
		factor *= 0.1;
	}
	return (result);
}

double	ft_atof(const char *nptr)
{
	double	result;
	double	type;

	result = 0;
	type = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			type = -1;
	}
	result = calc_integer_part(&nptr);
	if (isinf(result) || isnan(result))
		return (NAN);
	if (*nptr == '.')
		result += calc_decimal_part(&nptr);
	if (isinf(result) || isnan(result))
		return (NAN);
	if (*nptr != '\0')
		return (NAN);
	return (result * type);
}
