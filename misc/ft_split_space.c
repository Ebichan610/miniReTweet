/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 19:07:08 by yebi              #+#    #+#             */
/*   Updated: 2026/04/13 19:07:09 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static size_t	count_words(char const *str)
{
	size_t	word_count;
	size_t	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (!in_word && !ft_isspace(*str))
		{
			word_count++;
			in_word = 1;
		}
		else if (in_word && ft_isspace(*str))
			in_word = 0;
		str++;
	}
	return (word_count);
}

static char	*strndup_split(char const *s, size_t n)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (n + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_split(char **result, int i_max)
{
	int	i;

	i = 0;
	while (i < i_max)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**words_split(char **result, char const *s, size_t word_count)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (i < word_count)
	{
		n = 0;
		while (ft_isspace(*s) && *s)
			s++;
		while (!ft_isspace(*s) && *s)
		{
			n++;
			s++;
		}
		result[i] = strndup_split(s - n, n);
		if (result[i] == NULL)
		{
			free_split(result, (int)i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split_space(char const *s)
{
	char	**result;
	size_t	word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	return (words_split(result, s, word_count));
}
