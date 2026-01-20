/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:13:22 by yebi              #+#    #+#             */
/*   Updated: 2024/11/30 23:10:36 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	char	*start;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (result == NULL)
		return (NULL);
	start = result;
	while (s1_len-- > 0)
		*result++ = *s1++;
	while (s2_len-- > 0)
		*result++ = *s2++;
	*result = '\0';
	return (start);
}

// int main(void)
// {
//     char const *s1 = "abcdefg";
//     char const *s2 = "12345";
//     char *result;
//     result = ft_strjoin(s1,s2);
//     if(result == NULL)
//         printf("error\n");
//     else
//         printf("%s\n",result);
//     return (0);
// }
