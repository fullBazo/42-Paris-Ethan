/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:41:10 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/12 17:34:48 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int i = 0;
	int count;
	int j;
	while (s[i])
	{
		count = 0;
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				count = 1;
			y++;
		}
		if (count == 0)
			return (i);
		i++;
	}
	return (i);
}

int main(void)
{
	char *s = "hello";
	printf("%zu\n", strspn(s, "0123456789"));
	printf("%zu\n", ft_strspn(s, "0123456789"));
}
