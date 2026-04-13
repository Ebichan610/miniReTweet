/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 01:49:49 by ebichan           #+#    #+#             */
/*   Updated: 2026/04/13 18:30:36 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

static int	count_words(char *str)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*str)
	{
		if (!is_whitespace(*str) && !in_word)
		{
			in_word = true;
			count++;
		}
		else if (is_whitespace(*str))
			in_word = false;
		str++;
	}
	return (count);
}

static char	*get_word(char **str)
{
	char	*start;
	char	*word;
	int		len;

	while (**str && is_whitespace(**str))
		(*str)++;
	start = *str;
	len = 0;
	while (**str && !is_whitespace(**str))
	{
		(*str)++;
		len++;
	}
	if (len == 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

char	**ft_split_space(char *str)
{
	char	**result;
	int		count;
	int		i;

	if (str == NULL)
		return (NULL);
	count = count_words(str);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		result[i] = get_word(&str);
		if (result[i] == NULL)
		{
			free_strs(result);
			return (NULL);
		}
		i++;
	}
	result[count] = NULL;
	return (result);
}
