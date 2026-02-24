/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:12:40 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/24 16:17:04 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	int i;
	t_data data;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("Invalid number of args: 4 or 5\n");
		return (1);
	}
	while (av[i])
	{
		if (valid_arg(av[i++]) == NULL)
			return (1);
	}
	if (init_table(&data, av) != 0)
		return (1);
	if (init_data(&data) != 0)
		return (1);
	init_thread(&data);
	cleanup(&data);
	return (0);
}