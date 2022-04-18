#ifndef THREAD_H
# define THREAD_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef pthread_mutex_t t_mutex;

struct t_data
{
	t_mutex *p_mutex;
	int *num;
};

#endif