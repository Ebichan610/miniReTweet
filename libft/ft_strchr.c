/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:32 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 23:10:40 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s = "abcdefghijkl";
// 	int			c;

// 	c = 'p';
// 	printf("%p\n", strchr(s, c));
// 	printf("%p\n", ft_strchr(s, c));
// 	return (0);
// }
