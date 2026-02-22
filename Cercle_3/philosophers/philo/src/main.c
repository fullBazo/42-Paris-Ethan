/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:37:52 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/19 13:34:52 by ethan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	init_struct(t_data *d, char **av)
// {
// 	int	i;

// 	i = 1;
// 	while (av[i])
// 	{
// 		if (!is_valid_arg(av[i]))
// 		{
// 			printf("Error: invalid argument(s)\n");
// 			exit(1);
// 		}
// 		i++;
// 	}
// 	d->nb_philo = ft_atoi(av[1]);
// 	d->eat = 1;
// }

int	main(void)
{
	printf("%lld\n", convert_time());
	sleep(2);
	printf("%lld\n", convert_time());
}
