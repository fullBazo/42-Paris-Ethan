/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:31:37 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/22 13:26:32 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrv(char *str)
{
	int		i = 0;
	int		len = 0;
	char	temp;

	while (str[len])
		len++;
	while (i < len - 1)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - 1] = temp;
		i++;
	}
	return(str);
}

int	main(void)
{
	char	oui[] = "salut";
	printf("%s\n", ft_strrv(oui));
}
