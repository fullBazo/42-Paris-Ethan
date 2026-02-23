/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:37:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/23 15:08:06 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;
	pthread_t	*thread;
	int			i;

	if (ac != 5 && ac != 6)
		return ();
	i = 0;
	init_struct(&data, av);
	init_fork(&data);
	init_print_mutex(&data);
	philo = init_philo(&data);
	thread = malloc(sizeof(pthread_t) * data.nb_philo);
	if (!thread)
		return ();
	while (i < data.nb_philo)
	{
		pthread_create(&thread[i], NULL, routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < data.nb_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
