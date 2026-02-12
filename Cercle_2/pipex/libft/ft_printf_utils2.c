/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:06 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/03 14:17:54 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(unsigned int n, int uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += print_hex(n / 16, uppercase);
	count += print_char(base[n % 16]);
	return (count);
}

int	print_pointer(void *ptr)
{
	int				count;
	unsigned long	addr;

	count = 0;
	addr = (unsigned long)ptr;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += print_string("0x");
	count += print_hexlong(addr);
	return (count);
}

int	print_hexlong(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += print_hexlong(n / 16);
	count += print_char(base[n % 16]);
	return (count);
}
