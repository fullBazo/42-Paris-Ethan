/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:31:56 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/23 17:23:23 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	assign_forks(t_philo *philo, t_data *data, int i)
{
	if (philo->id % 2 == 0)
	{
		philo[i].right_fork = &data->forks[i];
		philo[i].left_fork = &data->forks[(i + 1) % data->nb_philo];
	}
	else
	{
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
	}
}

void	init_fork(t_data *data)
{
	int	i;

	data->forks = safe_malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
		safe_mtx(&data->forks[i++], INIT);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = safe_malloc(sizeof(t_philo) * data->nb_philo);
	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].last_meal = data->start_time;
		philo[i].meals = 0;
		assign_forks(philo, data, i);
		i++;
	}
	return (philo);
}

void	init_print_mutex(t_data *data)
{
	pthread_mutex_init(&data->p_mutex, NULL);
}

void	*routine(void *rout)
{
	t_philo	*data;

	data = (t_philo *)rout;
}

void	philo_1(t_philo *p)
{
	ft_print(p, "has taken a fork");
	usleep(convert_time() * 1000);
	ft_print(p, "died");
	return (0);
}