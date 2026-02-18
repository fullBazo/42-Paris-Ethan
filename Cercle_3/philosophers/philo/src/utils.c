/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:13:39 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/18 15:25:41 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_atoi(const char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}
