/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:10:48 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 23:10:20 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char		dst[] = "adsdfjafjasf";
// 	const char	*src = "093ur023";
// 	size_t		size;

// 	size = sizeof(dst);
// 	// strlcpy(dst, src, size);
// 	// printf("%s\n", dst);
// 	// printf("%c\n", strlcpy(dst, src, size));
// 	ft_strlcpy(dst, src, size);
// 	printf("%s\n", dst);
// 	printf("%zu\n", ft_strlcpy(dst, src, size));
// 	return (0);
// }
