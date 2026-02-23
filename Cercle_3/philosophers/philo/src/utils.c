/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:13:39 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/23 14:52:40 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

char	*valid_arg(char *str)
{
	int		len;
	char	*nb;

	len = 0;
	while (isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Only positives numbers");
	if (!isdigit(*str))
		error_exit("Only digit, please");
	nb = str;
	while (isdigit(*str++))
		len++;
	if (len > 10)
		error_exit("Value too big");
	return (nb);
}

long long	ft_atol(const char *str)
{
	long long	result;

	result = 0;
	str = valid_arg(str);
	while (isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (result > INT_MAX)
		error_exit("Value too big");
	return (result);
}

// long long	get_time(void)
// {
// 	struct timeval	tv;
// 	long long		res;

// 	res = 0;
// 	gettimeofday(&tv, NULL);
// 	res = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
// 	return (res);
// }

// void	ft_usleep(long long time)
// {
// 	long long	target;

// 	target = convert_time() + time;
// 	while (convert_time() < target)
// 	{
// 		usleep(100);
// 	}
// }

// void	ft_print(t_philo *p, char *str)
// {
// 	long long	time;

// 	time = convert_time() - p->data->start_time;
// 	pthread_mutex_lock(&p->data->p_mutex);
// 	printf("%lld %d %s", time, p->id, str);
// 	pthread_mutex_unlock(&p->data->p_mutex);
// }

void	error_exit(const char *error)
{
	printf("%s\n", error);
}