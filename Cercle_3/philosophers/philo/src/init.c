#include "../philo.h"

void	assign_forks(t_philo *philo, t_data *data, int i)
{
	if (philo[i].id % 2 == 0)
	{
		philo[i].left_fork = &data->forks[(i + 1) % data->nb_philo];
		philo[i].right_fork = &data->forks[i];
	}
	else
	{
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
	}
}

void	init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = data->philos;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].meals = 0;
		philo[i].full = false;
		philo[i].last_meal = convert_time();
		assign_forks(philo, data, i);
		i++;
	}
}

int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->end_simulation = false;
	data->start_time = convert_time();
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (1);
	while (i < data->nb_philo)
		safe_mtx(&data->forks[i++], INIT);
	safe_mtx(&data->p_mutex, INIT);
	init_philo(data);
	return (0);
}
