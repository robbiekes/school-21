#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DIED_MSG "is dead"
# define FORK_MSG "has taken a fork"

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
	int				start_time; // all philos must start eating at the same time
	t_fork			*right;
	t_fork			*left;
	t_fork			*message_mutex; // to lock/unlock message output when eating, sleeping, etc.
	t_fork			*meal_count; // 5th arg
	
}					t_philo;

typedef struct s_data // info about all threads and 
{
	int			philo_num;
	t_fork		*forks; // array of mutexes aka forks
	pthread_t	*thread_ids;
	t_philo		*philos;
	int			must_die;
}				t_data;

//main.c
int				check_args(int ac, char **av);

// init.c
int				init_phil_data(t_data *data, int ac, char **av);
int				init_data(t_data *data, int ac, char **av);
int				init_forks(t_data *data);

// philo.c
int				create_threads(t_data *data);
void			take_forks(t_philo *philo);
void			put_back_forks(t_philo *philo);
void			to_sleep(t_philo *philo);
void			to_eat(t_philo *philo);
void			*philosophers(void *arg);

// free
void			free_all(t_data *data);

// time.c
unsigned int	get_time_ms(void);

// utils.c
int				ft_atoi(char *str);
void			ft_usleep(unsigned int ms);
void			print_message(t_philo *philo, char *msg);
void			free_all(t_data *data);

// destroy_mutexes.c
void	check_death(t_data *data);
void	destroy_mutexes(t_data *data);

#endif