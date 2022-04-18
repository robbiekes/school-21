#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef pthread_mutex_t t_mutex;

typedef struct s_data 
{
	int philo_num; // == num of threads
	int time_to_eat; //in ms
	int time_to_die; //in ms
	int time_to_sleep; //in ms
	int *small;
	int *large;
} t_data;

#endif