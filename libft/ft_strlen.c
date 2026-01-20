/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:54:15 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 23:10:22 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

// int	main(void)
// {
// 	const char	*s = "akfj";

// 	printf("%zu\n", strlen(s));
// 	printf("%zu\n", ft_strlen(s));
// 	return (0);
// }
