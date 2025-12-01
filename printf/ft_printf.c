/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:52:31 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/26 17:50:12 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_sc
{
	int	len;
	int	width;
}				t_sc;


const char	*ft_read_text(t_sc *sc, const char *format)
{
	char *next;

	next = ft_strchr(format, );
	if (next)
		sc->width = next - format;
	else
		sc->width = ft_strlen(format);
	write(1, format, sc->width);
	sc->len += sc->width;
	while (*format && *format != '%')
		format++;
	return (format);
}

int	ft_printf(const char *format , ...)
{
	va_list	arg;
	va_start(arg, format);
	t_sc sc;
	sc.len = 0;
	sc.width = 0;

	while(*format)
	{
		if (*format == '%')
			format = ft_search_arg(arg, format + 1, &sc);
		else
			format = ft_read_text(&sc, format);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
		format++;
	}
	va_end(arg);
	return (sc.len);
}