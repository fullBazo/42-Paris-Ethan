/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:52:34 by ehuet             #+#    #+#             */
/*   Updated: 2025/12/01 11:27:02 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		printf_format(char c, va_list args);
int		ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_string(char *str);
int		print_decimal(int n);
int		print_unsigned_decimal(unsigned int n);
int		print_hex(unsigned int n, int uppercase);
int		print_pointer(void *ptr);
int		print_hexlong(unsigned long n);
#endif
