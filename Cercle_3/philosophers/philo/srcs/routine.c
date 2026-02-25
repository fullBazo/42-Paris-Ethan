/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:28:41 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/25 14:25:15 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	forks_taking(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	safe_mtx(p->left_fork, LOCK);
	ft_print(p, "has taken a fork\n");
	safe_mtx(p->right_fork, LOCK);
	ft_print(p, "has taken a fork\n");
	ft_print(p, "is eating\n");
}

void	*routine(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	if (p->id % 2 == 0)
		ft_usleep(p->data->time_to_eat);
	while (!p->data->end_simulation)
	{
		// p->last_meal = convert_time();
		forks_taking(p);
		p->last_meal = convert_time() - p->data->start_time;
		// printf("%lld\n", p->last_meal);
		// printf("%lld\n", p->data->time_to_die);
		ft_usleep(p->data->time_to_eat);
		p->meals++;
		safe_mtx(p->left_fork, UNLOCK);
		safe_mtx(p->right_fork, UNLOCK);
		if (p->meals == p->data->nb_meals)
		{
			p->full = true;
			return (NULL);
		}
		ft_print(p, "is sleeping\n");
		ft_usleep(p->data->time_to_sleep);
		ft_print(p, "is thinking\n");
		if (p->data->nb_philo % 2 != 0)
		{
			if ((2 * p->data->time_to_eat - p->data->time_to_sleep) > 0)
				ft_usleep(2 * p->data->time_to_eat - p->data->time_to_sleep);
		}
	}
	return (NULL);
}

static void	check_death(t_data *d, int i, int *full_count)
{
	if (!d->philos[i].full && ((convert_time() - d->start_time)
			- d->philos[i].last_meal) > d->time_to_die)
	{
		ft_print(&d->philos[i], "died\n");
		d->end_simulation = true;
	}
	if (d->philos[i].full)
		(*full_count)++;
}

void	*monitor(void *data)
{
	t_data	*d;
	int		i;
	int		full_count;

	d = (t_data *)data;
	while (!d->end_simulation)
	{
		full_count = 0;
		i = 0;
		while (i < d->nb_philo)
		{
			check_death(d, i, &full_count);
			if (d->end_simulation)
				return (NULL);
			i++;
		}
		if (full_count == d->nb_philo)
		{
			d->end_simulation = true;
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

void	*philo_1(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	safe_mtx(p->left_fork, LOCK);
	ft_print(p, "has taken a fork\n");
	ft_usleep(p->data->time_to_die);
	ft_print(p, "died\n");
	safe_mtx(p->left_fork, UNLOCK);
	return (NULL);
}
