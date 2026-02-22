/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 14:52:29 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/22 14:53:26 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	msg(int msg_code)
{
	if (msg_code == ERR_BASE)
		ft_putstr_fd("Error\n", 2);
	else if (msg_code == ERR_MALLOC)
		ft_putstr_fd("Error, malloc failed\n", 2);
	else if (msg_code == ERR_MUTEX)
		ft_putstr_fd("Error, mutex failed\n", 2);
	else if (msg_code == ERR_GET_TIME)
		ft_putstr_fd("Error, get_time failed\n", 2);
	else if (msg_code == ERR_ARGS_NB)
		ft_putstr_fd("Error, 4 or 5 arguments required\n", 2);
	else if (msg_code == ERR_ARGS_FORMAT)
		ft_putstr_fd("Error, arguments must be strict positive numbers\n", 2);
	return (msg_code);
}
