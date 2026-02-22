/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:37:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/22 15:56:41 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_struct(t_data *d, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_valid_arg(av[i]))
		{
			return (ERR_ARGS_FORMAT);
			exit(1);
		}
		i++;
		d->nb_philo = ft_atoi(av[1]);
		d->eat = 1;
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;
	int			i;

	if (ac != 5 || ac != 6)
		return (ERR_ARGS_NB);
	init_struct(&data, av);
	init_fork(&data);
	init_print_mutex(&data);
	philo = init_philo(&data);
	thread = malloc(sizeof(pthread_t) * data.nb_philo);
	if (!thread)
		return (ERR_MALLOC);
	while (i < data.nb_philo)
	{
		pthread_create(&philo[i], NULL, routine, &thread[i]);
		i++;
	}
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
