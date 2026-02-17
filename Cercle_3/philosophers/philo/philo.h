/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:23:23 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/17 16:13:29 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	
}	t_philo;

typedef struct s_data
{
	int	nb_philo;
	int die;
	int eat;
	int sleep;
	int	must_eat;
}	t_data;

void	*philo_eat(t_data *d);

#endif
