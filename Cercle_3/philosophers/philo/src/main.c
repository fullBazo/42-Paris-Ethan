/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:37:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/18 15:39:59 by ehuet            ###   ########.fr       */
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
			printf("Error: invalid argument(s)\n");
			exit(1);
		}
		i++;
	}
	d->nb_philo = ft_atoi(av[1]);
	d->eat = 1;
}

int	main(int ac, char **av)
{
	pthread_t	*threads;
	int			len_thread;
	int			i;
	t_data		d;

	if (ac != 2)
		return (1);
	init_struct(&d, av);
	len_thread = ft_atoi(av[1]);
	threads = calloc(len_thread, sizeof(pthread_t));
	i = 0;
	pthread_mutex_init(&d.p_mutex, NULL);
	while (i < d.nb_philo)
	{
		pthread_create(threads + i, NULL, philo_eat, &d);
		i++;
	}
	i = 0;
	while (i < d.nb_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}
