/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:56:55 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 23:10:39 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (t == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		t[i] = (char)s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

// int	main(void)
// {
//     const char *s ="abcdefgh";
//     printf("%s\n",ft_strdup(s));
//     printf("%s\n",strdup(s));
//     return (0);
// }
