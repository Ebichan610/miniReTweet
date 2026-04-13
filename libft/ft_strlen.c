/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:54:15 by yebi              #+#    #+#             */
/*   Updated: 2026/04/13 01:44:11 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if(s == NULL)
		return(0);
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
