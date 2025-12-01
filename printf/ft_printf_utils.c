/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:52:18 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/01 11:35:47 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}	
	return (count);
}

int	print_decimal(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (n < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += print_decimal(nb / 10);
	count += print_char((nb % 10) + '0');
	return (count);
}

int	print_unsigned_decimal(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += print_unsigned_decimal(n / 10);
	count += print_char((n % 10) + '0');
	return (count);
}
