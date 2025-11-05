/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:14:05 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/05 18:52:06 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*strrchr(const char *str, int c)
{
	const char *last = NULL;

	while (*str)
	{
		if (*str == (char)c)
			last = str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);

	return ((char *)last);
}