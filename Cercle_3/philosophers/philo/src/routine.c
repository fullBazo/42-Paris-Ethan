#include "../philo.h"

void	*routine(void *data)
{
	t_philo	*p;

	p = (t_philo *)data;
	if (p->id % 2 == 0)
		ft_usleep(p->data->time_to_eat);
	while (!p->data->end_simulation)
	{
		p->last_meal = convert_time();
		safe_mtx(p->left_fork, LOCK);
		ft_print(p, "has taken a fork\n");
		safe_mtx(p->right_fork, LOCK);
		ft_print(p, "has taken a fork\n");
		ft_print(p, "is eating\n");
		p->last_meal = convert_time();
		ft_usleep(p->data->time_to_eat);
		p->meals++;
		safe_mtx(p->left_fork, UNLOCK);
		safe_mtx(p->right_fork, UNLOCK);
		if (p->meals == p->data->nb_meals)
		{
			p->full = true;
			break ;
		}
		ft_print(p, "is sleeping\n");
		ft_usleep(p->data->time_to_sleep);
		ft_print(p, "is thinking\n");
	}
	return (NULL);
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
			if (!d->philos[i].full)
			{
				if ((convert_time() - d->philos[i].last_meal) > d->time_to_die)
				{
					ft_print(&d->philos[i], "died\n");
					d->end_simulation = true;
					return (NULL);
				}
			}
			if (d->philos[i].full)
				full_count++;
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

void	init_thread(t_data *data)
{
	int	i;

	i = -1;
	if (data->nb_meals == 0)
		return ;
	else if (data->nb_philo == 1)
		return ;
	else
	{
		while (++i < data->nb_philo)
			safe_thread(&data->philos[i].thread, routine, &data->philos[i],
				CREATE);
		safe_thread(&data->monitor, monitor, data, CREATE);
		i = -1;
		while (++i < data->nb_philo)
			safe_thread(&data->philos[i].thread, routine, &data->philos[i],
				JOIN);
		safe_thread(&data->monitor, monitor, data, JOIN);
	}
}
