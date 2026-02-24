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
	_Atomic int meals;
	_Atomic long long last_meal;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
	_Atomic bool full;
}						t_philo;

typedef struct s_data
{
	_Atomic bool end_simulation;
	int					nb_philo;
	int					must_eat;
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

void					ft_print(t_philo *p, char *str);
long long				convert_time(void);
long long				ft_atol(char *str);
char					*valid_arg(char *str);
void					ft_usleep(long long time);
void					init_philo(t_data *data);
int						init_table(t_data *data, char **av);
int						init_data(t_data *data);
void					init_thread(t_data *data);
void					safe_mtx(pthread_mutex_t *mtx, t_mtx code);
void					safe_thread(pthread_t *thread, void *(*foo)(void *),
							void *data, t_mtx code);
void					cleanup(t_data *data);

#endif
