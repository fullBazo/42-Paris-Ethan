/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:01:22 by ehuet             #+#    #+#             */
/*   Updated: 2025/09/22 10:11:40 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dlen;
	unsigned int	slen;

	dlen = 0;
	while (dlen < size && dest[dlen] != '\0')
		dlen++;
	slen = 0;
	while (src[slen] != '\0')
		slen++;
	if (dlen == size)
		return (size + slen);
	i = 0;
	while (src[i] != '\0' && dlen + i + 1 < size)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
/*
int	main(void)
{
	char tab1[25] = "salut euhehehuh";
	char tab2[28] = " a touswieiwj";

	printf("%d\n", ft_strlcat(tab1, tab2, 6));
}
*/
