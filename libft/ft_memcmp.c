/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:06:28 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/07 14:06:38 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *p1, const void *p2, size_t size)
{
	const unsigned char	*s1 = (const unsigned char *)p1;
	const unsigned char	*s2 = (const unsigned char *)p2;
	size_t				i;

	if (size < 1)
		return (0);
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
}
*/