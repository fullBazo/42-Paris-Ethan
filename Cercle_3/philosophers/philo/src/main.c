/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:37:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/17 16:07:25 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_struct(t_data *d, int ac)
{
	d->nb_philo = ac;
}

int	main(int ac, char **av)
{
	pthread_t philosophers[ac - 1];
	int	i;
	t_data d;
	(void)av;

	i = 0;
	if (ac == 2)
	{
		init_struct(&d, ac);
		while (i < ac)
			pthread_create(philosophers + i, NULL, philo_eat, NULL);
		i = 0;
		while (i < ac)
			pthread_join(philosophers[i], NULL);
	}
}
