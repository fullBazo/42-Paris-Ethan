/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:29:05 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/26 14:57:48 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[size] = 0;
	return (res);
}

char	*ft_strchr(const char *s1, int c)
{
	char	*s2;

	s2 = (char *)s1;
	while (*s2 != c && *s2 != 0)
		s2++;
	if (*s2 == c)
		return (s2);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t ec, size_t es)
{
	char	*res;

	res = malloc(es * ec);
	if (!res)
		return (NULL);
	ft_bzero(res, es * ec);
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
