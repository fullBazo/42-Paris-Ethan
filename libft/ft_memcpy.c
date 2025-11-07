/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:06:24 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/07 10:45:27 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	*str;
	char	dest[] = "Hello world";

	str = "Hello world";
	ft_memcpy(dest, str + 2, 3);
	printf("%s\n", dest);
	memcpy(dest, str + 2, 3);
	printf("%s\n", dest);
	memmove(dest, str + 2, 3);
	printf("%s\n", dest);
	return (0);
}
*/