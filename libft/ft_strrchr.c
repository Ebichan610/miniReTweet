/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:40:10 by yebi              #+#    #+#             */
/*   Updated: 2026/04/13 18:28:03 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*result;

	result = NULL;
	while (*s)
	{
		if (*s == (char)c)
			result = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)result);
}

// int	main(void)
// {
// 	const char	*s = "abcafhgiai";
// 	int			c;

// 	c = '0';
// 	printf("%p\n", strrchr(s, c));
// 	printf("%p\n", ft_strrchr(s, c));
// 	return (0);
// }
