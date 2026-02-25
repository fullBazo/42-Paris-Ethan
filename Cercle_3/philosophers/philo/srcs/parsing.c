/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:28:39 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/25 13:28:40 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_table(t_data *data, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atol(av[i++]) == -1)
			return (printf("Invalid argument\n"), 1);
	}
	data->nb_philo = ft_atol(av[1]);
	if (data->nb_philo > 199 || data->nb_philo == 0)
		return (printf("Philos must be between 1 and 199\n"), 1);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		data->nb_meals = ft_atol(av[5]);
	else
		data->nb_meals = -1;
	return (0);
}
