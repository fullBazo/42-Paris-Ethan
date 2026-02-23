/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:23:23 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/23 17:21:18 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_mtx
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}					t_mtx;

typedef struct s_data
{
	int				nb_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	p_mutex;
	int				someone_died;
	long long		start_time;
	long long		nbr_limit_meals;
	bool			end_simulation;
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

void				ft_print(t_philo *p, char *str);
long long			convert_time(void);
int					is_valid_arg(char *str);
long long			ft_atol(const char *str);

// Init datas
void				init_fork(t_data *data);
t_philo				*init_philo(t_data *data);
void				init_print_mutex(t_data *data);

// Safe error handle
void				*safe_malloc(size_t bytes);
void				safe_mtx(pthread_mutex_t *mtx, t_mtx code);
void				safe_thread(pthread_t *thread, void *(*foo)(void *),
						void *data, t_mtx code);

void				error_exit(const char *error);

#endif
