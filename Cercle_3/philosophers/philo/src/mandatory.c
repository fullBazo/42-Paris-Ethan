/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:31:56 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/19 13:11:25 by ethan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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

t_philo	*init_philo(t_data *data)
{
	t_philo *p;
	int i;

	p = malloc(sizeof(t_philo) * data->nb_philo);
	if (!p)
		exit(1);
	i = 0;
	while (i < data->nb_philo)
	{
		p[i].id = i + 1;
		p[i].data = data;
		p[i].left_fork = &data->forks[i];
		p[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		p[i].last_meal = data->start_time;
		p[i].meals = 0;
		i++;
	}
	return (p);
}

void	init_print_mutex(t_data *data)
{
	pthread_mutex_init(&data->p_mutex, NULL);
}