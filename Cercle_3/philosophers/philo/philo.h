/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuet <ehuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:35:05 by ehuet             #+#    #+#             */
/*   Updated: 2026/02/26 12:02:15 by ehuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef enum e_mtx
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}						t_mtx;

typedef struct s_philo
{
	int					id;
	_Atomic int			meals;
	_Atomic long long	last_meal;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
	_Atomic bool		full;
}						t_philo;

typedef struct s_data
{
	_Atomic bool		end_simulation;
	int					nb_philo;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			start_time;
	long long			nb_meals;
	pthread_t			monitor;
	pthread_mutex_t		*forks;
	pthread_mutex_t		p_mutex;
	t_philo				*philos;
}						t_data;

// utils.c
bool					is_digit(char c);
bool					is_space(char c);
char					*valid_arg(char *str);
long long				ft_atol(char *str);

// utils2.c
long long				convert_time(void);
void					ft_usleep(long long time, t_data *data);
void					ft_print(t_philo *p, char *str);
void					cleanup(t_data *data);

// parsing.c
int						init_table(t_data *data, char **av);

// init.c
void					assign_forks(t_philo *philo, t_data *data, int i);
void					init_philo(t_data *data);
int						init_data(t_data *data);

// safe_alloc.c
void					thread_or_mtx_error(int status);
void					safe_mtx(pthread_mutex_t *mtx, t_mtx code);
void					safe_thread(pthread_t *thread, void *(*foo)(void *),
							void *data, t_mtx code);

// routine.c
void					*routine(void *data);
void					*monitor(void *data);
void					*philo_1(void *data);
void					init_thread(t_data *data);
void					eating(t_philo *p);

// main.c
int						main(int ac, char **av);

#endif
