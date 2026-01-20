/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:43:22 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 01:16:46 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;
	size_t				i;

	s1_cpy = (const unsigned char *)s1;
	s2_cpy = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_cpy[i] != s2_cpy[i])
			return (s1_cpy[i] - s2_cpy[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	*s1 = "1234568";
// 	const char	*s2 = "1234567";

// 	printf("%d\n", memcmp(s1, s2, 7));
// 	printf("%d\n", ft_memcmp(s1, s2, 7));
// 	return (0);
// }
