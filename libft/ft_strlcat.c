/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:44:09 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 23:10:35 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char		dst[] = "ehioaeio";
// 	const char	*src = "0193012";
// 	size_t		size;
// 	size_t		total_len;

// 	size = sizeof(dst);
// 	total_len = ft_strlcat(dst, src, size);
// 	printf("%s\n%zu\n", dst, total_len);
// 	return (0);
// }
