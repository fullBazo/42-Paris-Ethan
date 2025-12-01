/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:52:31 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/01 11:26:51 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(args, int));
	else if (c == 's')
		count += print_string(va_arg(args, char *));
	else if (c == 'p')
		count += print_pointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		count += print_decimal(va_arg(args, int));
	else if (c == 'u')
		count += print_unsigned_decimal(va_arg(args, unsigned int));
	else if (c == 'x')
		count += print_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count += print_hex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				count += printf_format(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
