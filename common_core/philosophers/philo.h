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
}			t_fork;

typedef struct s_philo // info about ONE philosopher
{
	unsigned int	time_to_eat; //in ms
	unsigned int	time_to_die; //in ms
	unsigned int	time_to_sleep; //in ms
	unsigned int	last_meal; // in ms
	int				own_num;
	int				each_must_eat; // how many time each philo must eat
	int				*must_die; // turns into 1 when philo died and checked by is_dead()
	int				start_time; // all philos must start eating at the same time
	t_fork			*right;
	t_fork			*left;
	pthread_t		write_mutex; // purpose?????????????
}					t_philo;

typedef struct s_data // info about all threads and 
{
	int			philo_num;
	t_fork		**forks; // array of mutexes aka forks
	pthread_t	*thread_ids;
	t_philo		**philos;
	int			must_die;
}				t_data;


// free
void	free_all(t_data *data);

// time value
unsigned int	get_time_ms(void);

#endif