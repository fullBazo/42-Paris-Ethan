/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:28:50 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/26 10:38:35 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	convert_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long long time, t_data *data)
{
	long long	target;

	target = convert_time() + time;
	while (convert_time() < target)
	{
		if (data->end_simulation)
			return ;
		usleep(100);
	}
}

void	ft_print(t_philo *p, char *str)
{
	long long	time;

	time = convert_time() - p->data->start_time;
	safe_mtx(&p->data->p_mutex, LOCK);
	if (!p->data->end_simulation)
		printf("%lld %d %s", time, p->id, str);
	safe_mtx(&p->data->p_mutex, UNLOCK);
}

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
		safe_mtx(&data->forks[i++], DESTROY);
	safe_mtx(&data->p_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}
