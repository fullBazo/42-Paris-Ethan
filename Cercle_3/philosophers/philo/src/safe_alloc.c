#include "../philo.h"

void	thread_or_mtx_error(int status)
{
	if (status != 0)
	{
		printf("mutex or thread init failed");
		return ;
	}
	return ;
}

void	safe_mtx(pthread_mutex_t *mtx, t_mtx code)
{
	if (LOCK == code)
		thread_or_mtx_error(pthread_mutex_lock(mtx));
	else if (UNLOCK == code)
		thread_or_mtx_error(pthread_mutex_unlock(mtx));
	else if (INIT == code)
		thread_or_mtx_error(pthread_mutex_init(mtx, NULL));
	else if (DESTROY == code)
		thread_or_mtx_error(pthread_mutex_destroy(mtx));
}

void	safe_thread(pthread_t *thread, void *(*foo)(void *), void *data,
		t_mtx code)
{
	if (CREATE == code)
		thread_or_mtx_error(pthread_create(thread, NULL, foo, data));
	else if (JOIN == code)
		thread_or_mtx_error(pthread_join(*thread, NULL));
	else if (DETACH == code)
		thread_or_mtx_error(pthread_detach(*thread));
}
