/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:45:27 by ehuet             #+#    #+#             */
/*   Updated: 2026/01/15 20:33:57 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_atol(const char *str, int *out)
{	
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		res = res * 10 + (*str - '0');
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (0);
		str++;
	}
	*out = res * sign;
	return (1);
}

void	is_max_min(t_node *stack, char *str, int *out)
{
	if (!ft_atol(str, out))
	{
		write(2, "Error\n", 6);
		free_stack(stack);
		exit(1);
	}
}

void	is_new_null(t_node *new)
{
	if (!new)
	{
		write(2, "Error\n", 6);
		free_stack(new);
		exit(1);
	}
}
