/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:44:16 by yebi              #+#    #+#             */
/*   Updated: 2024/11/29 19:29:45 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = (unsigned char *)s;
	while (n-- > 0)
	{
		*s_cpy = 0;
		s_cpy++;
	}
}

// int	main(void)
// {
// 	unsigned char	s[] = "hieur";

// 	// bzero(s, 4);
// 	// printf("%s\n", s);
// 	ft_bzero(s, 4);
// 	printf("%s\n", (char *)s);
// 	return (0);
// }
