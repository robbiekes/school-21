#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "is dead"
# define FORK "has taken a fork"

typedef pthread_mutex_t p_mutex;

typedef struct s_fork
{
	p_mutex	mutex;
	int		num;
} t_fork;

typedef struct s_philo // info about ONE philosopher
{
	int				own_num;
	unsigned int	time_to_eat; //in ms
	unsigned int	time_to_die; //in ms
	unsigned int	time_to_sleep; //in ms
	int				each_must_eat; // how many time each philo must eat
	unsigned int	last_meal; // tv_sec (sec), tv_usec(mcs)
	int				*must_die;
	t_fork			*right;
	t_fork			*left;
	int				start_time; // in ms
} t_philo;

typedef struct s_data // info about all threads and 
{
	int			philo_num;
	t_fork		**forks; // array of mutexes aka forks
	pthread_t	*thread_ids;
	t_philo		**philos;
	int			must_die;
} t_data;


// free
void	free_all(t_data *data);

// time value
unsigned int	get_time_ms(void);

#endif