/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:28:36 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/25 13:28:37 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	int		i;
	t_data	data;

	i = 1;
	if (ac != 5 && ac != 6)
		return (printf("Usage: ./philo n t_die t_eat t_sleep [n_meals]\n"), 1);
	while (av[i])
		if (valid_arg(av[i++]) == NULL)
			return (1);
	if (init_table(&data, av) != 0)
		return (1);
	if (init_data(&data) != 0)
		return (printf("Init error\n"), 1);
	init_thread(&data);
	cleanup(&data);
	return (0);
}
