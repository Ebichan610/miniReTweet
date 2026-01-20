/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yebi <yebi@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:58:55 by yebi              #+#    #+#             */
/*   Updated: 2024/12/01 01:33:37 by yebi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	word_count;
	size_t	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (!in_word && *str != c)
		{
			word_count++;
			in_word = 1;
		}
		else if (in_word && *str == c)
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

static char	**words_split(char **result, char const *s, char c,
		size_t word_count)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (i < word_count)
	{
		n = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	return (words_split(result, s, c, word_count));
}

// int	main(void)
// {
// 	char const	*s;
// 	char		c;
// 	char		**result;
// 	int			i;

// 	s = "asfie1iafi111iaef11iai1";
// 	c = '1';
// 	i = 0;
// 	result = ft_split(s, c);
// 	if (result == NULL)
// 	{
// 		printf("arrayisNULL\n");
// 		return (1);
// 	}
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	return (0);
// }
