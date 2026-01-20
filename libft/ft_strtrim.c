/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:39:28 by yebi              #+#    #+#             */
/*   Updated: 2024/12/01 01:41:09 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	removed_check(char const s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return ((0));
}

static size_t	removed_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start])
	{
		if (!removed_check(s1[start], set))
			break ;
		start++;
	}
	return (start);
}

static size_t	removed_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	if (end == 0)
		return (0);
	end--;
	while (end > 0)
	{
		if (!removed_check(s1[end], set))
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	len;

	start = removed_start(s1, set);
	end = removed_end(s1, set);
	if (start > end || (start == 0 && end == 0))
		len = 0;
	else
		len = end - start + 1;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, &s1[start], len + 1);
	return (result);
}

// int main(void)
// {
//     char const *s1 = "my favorite food is sushi";
//     char const *set = " s";
//     char *result;

//     result = ft_strtrim(s1,set);
//     if(result == NULL)
//         printf("error\n");
//     else
//         printf("%s\n",result);
//     return (0);
// }
