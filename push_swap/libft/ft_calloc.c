/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:06:39 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/12 14:37:34 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (count != 0 && size != 0)
	{
		total = count * size;
		if (total / size != count)
			return (NULL);
	}
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
