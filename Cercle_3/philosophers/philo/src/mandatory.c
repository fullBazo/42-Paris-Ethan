/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:31:56 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/18 16:01:38 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_eat(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (d->eat <= d->nb_philo)
	{
		pthread_mutex_lock(&d->p_mutex);
		printf("Philo %lld is eating\n", d->eat);
		d->eat++;
		pthread_mutex_unlock(&d->p_mutex);
	}
	return (NULL);
}

void	init_fork(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		exit(1);
	i = 0;
	while (i < data->nb_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
}
