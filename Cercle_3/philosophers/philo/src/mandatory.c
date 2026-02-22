/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:31:56 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/22 16:06:10 by ehuet            ###   ########.fr       */
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
	t_philo	*p;
	int		i;

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

void	*routine(void *rout)
{
	t_philo *data;

	data = (t_philo *)rout;
	if (data->data->nb_philo == 1)
	{
		pthread_mutex_lock(data->data->forks);
		printf("Philo 1 has taken a fork");
		usleep(data->data->die);
		printf("Philo 1 has died");
		return (NULL);
	}
}