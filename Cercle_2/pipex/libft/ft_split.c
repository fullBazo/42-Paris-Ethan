/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:32:59 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/26 13:44:19 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	safe_malloc(char **words, int pos, size_t buffer)
{
	int	i;

	i = 0;
	words[pos] = malloc(buffer);
	if (!words[pos])
	{
		while (i < pos)
		{
			free(words[i]);
			++i;
		}
		free(words);
		return (1);
	}
	return (0);
}

static size_t	count_words(const char *str, char c)
{
	size_t	total;
	size_t	i;

	i = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == 0))
			total++;
		i++;
	}
	return (total);
}

static int	fill_word(char **words, const char *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s != 0)
			++s;
		while (*s != c && *s != 0)
		{
			++len;
			++s;
		}
		if (len > 0)
		{
			if (safe_malloc(words, i, len + 1))
				return (1);
			ft_strlcpy(words[i], s - len, len + 1);
			++i;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i <= words)
	{
		res[i] = NULL;
		i++;
	}
	res[words] = NULL;
	if (fill_word(res, s, c))
		return (NULL);
	return (res);
}
/*
int	main(void)
{
	char	*str = "  e salut, les, amis, comment, ca, va,";
	char	**c = ft_split(str, ' ');
	size_t	i;

	i = 0;
	while (c[i])
	{	
		printf("%s\n", c[i]);
		free(c[i]);
		i++;
	}
	free(c);
}
*/
