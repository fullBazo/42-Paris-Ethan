#include "../philo.h"

int	init_table(t_data *data, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i]) == -1)
		{
			printf("Number too big\n");
			return (1);
		}
		i++;
	}
	data->nb_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		data->nb_meals = ft_atol(av[5]);
	else
		data->nb_meals = -1;
	return (0);
}
