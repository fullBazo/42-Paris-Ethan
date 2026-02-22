/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:13:39 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/19 13:34:53 by ethan            ###   ########.fr       */
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

long long	convert_time(void)
{
	struct timeval tv;
	long long res;

	res = 0;
	gettimeofday(&tv, NULL);
	tv.tv_sec *= 1000;
	tv.tv_usec /= 1000;
	res = tv.tv_sec + tv.tv_usec;
	return (res);
}