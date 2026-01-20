/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 01:40:53 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 23:10:27 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}

// int main(void)
// {
//     const char *s = "abcdefghijklmnop";
//     char *substr = ft_substr(s,'z',6);
//     if(substr == NULL)
//         printf("error\n");
//     else
//         printf("%s\n",substr);
//     return (0);
// }
