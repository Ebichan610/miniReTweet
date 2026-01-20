/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:26:06 by ebichan           #+#    #+#             */
/*   Updated: 2024/11/30 22:24:19 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (11);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	convert_to_string(int n, char *result, size_t len)
{
	result[len--] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		result[len--] = '0' + (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	len = ft_numlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_strlcpy(result, "-2147483648", 12);
			return (result);
		}
		n *= -1;
		result[0] = '-';
	}
	convert_to_string(n, result, len);
	return (result);
}

// int main()
// {
//     printf("%s\n",ft_itoa(0));
//     return (0);
// }
