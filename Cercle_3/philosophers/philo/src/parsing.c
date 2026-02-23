/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:01:08 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/23 15:11:58 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_table(t_data *data, char **av)
{
	data->nb_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]) * 1000;
	data->time_to_eat = ft_atol(av[3]) * 1000;
	data->time_to_sleep = ft_atol(av[4]) * 1000;
	// if (data->time_to_die < 60000 || data->time_to_eat < 60000
	// 	|| data->time_to_sleep < 60000)
	// 	error_exit("Your timestamps needs to be greater than 60ms");
	if (av[5])
		data->nbr_limit_meals = fr_atol(av[5]);
	else
		data->nbr_limit_meals = -1;
}
