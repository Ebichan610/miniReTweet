/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:55:38 by yebi              #+#    #+#             */
/*   Updated: 2024/12/01 02:58:29 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			bytes;
	void			*s;
	size_t			i;
	unsigned char	*s_cpy;

	bytes = nmemb * size;
	s = malloc(bytes);
	if (s == NULL || (size && bytes / size != nmemb))
		return (NULL);
	s_cpy = (unsigned char *)s;
	i = 0;
	while (i < bytes)
	{
		s_cpy[i] = 0;
		i++;
	}
	return (s);
}

// int	main(void)
// {
//     size_t nmemb;
//     int *array;

//     nmemb = 0;
//     array=ft_calloc(nmemb,sizeof(int));
//     // array=calloc(nmemb,sizeof(int));
//     if(array==NULL)
//     printf("arrayisNULL\n");
//     size_t i;
//     i=0;
//     while(i < nmemb)
//     {
//         printf("%d\n",array[i]);
//         i++;
//     }
//     return (0);
// }
