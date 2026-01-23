/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:45:21 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/17 14:54:20 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(long n)
{
	size_t	digit;

	digit = (n <= 0);
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nb;
	long	max;

	max = n;
	nb = count_char(max);
	result = malloc(sizeof(char) * (nb + 1));
	if (!result)
		return (NULL);
	result[nb--] = '\0';
	if (max == 0)
		result[0] = '0';
	if (max < 0)
	{
		result[0] = '-';
		max = -max;
	}
	while (max > 0)
	{
		result[nb--] = max % 10 + '0';
		max /= 10;
	}
	return (result);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));

}
*/