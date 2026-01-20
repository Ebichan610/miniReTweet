/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:14:04 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 19:36:30 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	d_cpy = (unsigned char *)dest;
	s_cpy = (unsigned char *)src;
	i = 0;
	if (d_cpy > s_cpy && d_cpy < s_cpy + n)
	{
		while (n-- > 0)
			d_cpy[n] = s_cpy[n];
	}
	else
	{
		while (i < n)
		{
			d_cpy[i] = s_cpy[i];
			i++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char		dest[] = "aiffiaeh";
// 	const char	src[] = "98327418923";

// 	printf("%s\n", (char *)memmove(dest, src, 7));
// 	// printf("%s\n", (char *)ft_memmove(dest, src, 10));
// 	return (0);
// }
