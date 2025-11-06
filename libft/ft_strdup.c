/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:21:25 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/05 17:12:13 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
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

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;

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
