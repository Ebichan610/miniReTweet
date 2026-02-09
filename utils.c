/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebichan <ebichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:23:48 by ebichan           #+#    #+#             */
/*   Updated: 2026/02/04 20:18:55 by ebichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

size_t	count_words(char const *str)
{
	size_t	word_count;
	size_t	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (!in_word && !(*str == ' ' || *str == '\n'))
		{
			word_count++;
			in_word = 1;
		}
		else if (in_word && (*str == ' ' || *str == '\n'))
			in_word = 0;
		str++;
	}
	return (word_count);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while(s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return((unsigned char)s1[i] - (unsigned char)s2[i]);
}
