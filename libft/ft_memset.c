/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:08:00 by yebi              #+#    #+#             */
/*   Updated: 2024/11/29 19:30:21 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_cpy[i] = c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	s[] = "aofhauiwehf";
// 	int		c;
// 	size_t	n;

// 	c = 'a';
// 	n = 5;
// 	memset(s, c, n);
// 	printf("%s\n", (char *)s);
// 	// printf("%s\n", (char *)ft_memset(s, c, n));
// 	return (0);
// }
