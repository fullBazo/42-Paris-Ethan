/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:52:34 by ehuet             #+#    #+#             */
/*   Updated: 2025/11/26 17:49:08 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_string(char *str);
int		print_integer(int n);
int		print_unsigned_integer(unsigned int n);
int		print_hexadecimal(unsigned int n, char specifier);
int		print_pointer(void *ptr);
int		print_percent(void);
#endif
