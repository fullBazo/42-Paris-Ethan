/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethan <ethan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:23:23 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/19 13:24:47 by ethan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				nb_philo;
	long long		die;
	long long		eat;
	long long		sleep;
	int				must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	p_mutex;
	int				someone_died;
	long long		start_time;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				meals;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

long long			convert_time(void);
int					is_valid_arg(char *str);
long long			ft_atoi(const char *str);

#endif
