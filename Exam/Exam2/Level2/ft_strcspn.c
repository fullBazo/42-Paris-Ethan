/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:12:36 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/12 17:17:14 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	int y;
	while (s[i])
	{
		y = 0;
		while (reject[y])
		{
			if (s[i] != reject[y])
				y++;
			else
				return (i);
		}
		i++;
	}
	return (i);
}

int main(void)
{
	printf("%zu\n", strcspn("hello", "0123456789"));
	printf("%zu\n", ft_strcspn("hello", "0123456789"));
}
