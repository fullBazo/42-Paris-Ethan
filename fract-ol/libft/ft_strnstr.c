/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:14:02 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/10 13:17:30 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] != '\0'
			&& str[i + j] == to_find[j]
			&& i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int     main(void)
{
        char    *str = "salut a tous";
        char    *to_find = "lu";

        printf("%s\n", strstr(str, to_find));
        printf("%s\n", ft_strnstr(str, to_find, 5));
        return (0);
}
*/
