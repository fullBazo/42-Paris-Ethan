/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:21:25 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/20 14:52:23 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(src) + 1;
	dup = malloc(len * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}
/*
int	main(void)
{
	char	*str = "salut";
	printf("La copie contient : %s\n", ft_strdup(str));
}
*/
