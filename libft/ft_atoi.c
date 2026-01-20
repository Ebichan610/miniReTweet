/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:54:43 by yebi              #+#    #+#             */
/*   Updated: 2024/11/29 23:13:37 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && (result > LONG_MAX / 10 || (result == LONG_MAX / 10
					&& (*nptr - '0') >= LONG_MAX % 10)))
			return (INT_MAX);
		if (sign == -1 && (result > -(LONG_MIN / 10) || (result == -(LONG_MIN
						/ 10) && (*nptr - '0') > -(LONG_MIN % 10))))
			return (INT_MIN);
		result = result * 10 + (long)(*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}

// int	main(void)
// {
// 	const char	*nptr = "-2222222222222";

// 	printf("%d\n", atoi(nptr));
// 	printf("%d\n", ft_atoi(nptr));
// 	return (0);
// }
