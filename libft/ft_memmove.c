/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:06:22 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/10 11:07:37 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest > src)
	{
		while (size > 0)
		{
			size--;
			((unsigned char *)dest)[size] = ((const unsigned char *)src)[size];
		}
	}
	else
	{
		while (i < size)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*
int	main(void)
{
	char	str[] = "abcdefghijklmnopqrstuvwxyz";
	//char	dest[20];

	memcpy(str + 5, str + 3, 7);
	printf("memcpy = %s\n", str);

	memmove(str + 5, str + 3, 7);
	printf("memmove = %s\n", str);

	return (0);
}
*/