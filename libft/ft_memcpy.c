/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:25:22 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 19:37:28 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d_cpy;
	const unsigned char	*s_cpy;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	d_cpy = (unsigned char *)dest;
	s_cpy = (const unsigned char *)src;
	while (n-- > 0)
	{
		*d_cpy = *s_cpy;
		d_cpy++;
		s_cpy++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	dest[] = "jfiejwow";
// 	char	src[] = "9834910";

// 	memcpy(dest, src, 100);
// 	printf("%s\n", dest);
// 	// ft_memcpy(dest, src, 100);
// 	// printf("%s\n", dest);
// 	return (0);
// }
