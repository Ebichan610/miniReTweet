/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:20:04 by yebi              #+#    #+#             */
/*   Updated: 2024/12/01 06:00:54 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cpy;
	size_t				i;

	i = 0;
	s_cpy = (const unsigned char *)s;
	while (i < n)
	{
		if (s_cpy[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s = "abcdefghi";
// 	int			c;

// 	c = 'd';
// 	printf("%s\n", (const char *)memchr(s, c, 5));
// 	printf("%s\n", (const char *)ft_memchr(s, c, 5));
// 	return (0);
// }
