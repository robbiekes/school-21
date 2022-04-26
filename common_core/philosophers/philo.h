/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:45:48 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 15:46:50 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define FORK_MSG "has taken a fork"

typedef pthread_mutex_t	t_mutex;

// fork has it's order number and mutex
typedef struct s_fork
{
	t_mutex		mutex;
	int			num;
}				t_fork;

// time_to_eat, time_to_sleep, time_to_die - in ms
typedef struct s_philo // info about ONE philosopher
{
	int64_t		time_to_eat;
	int64_t		time_to_sleep;
	int64_t		last_meal;
	int64_t		start_time;
	t_fork		*right;
	t_fork		*left;
	t_mutex		*message_mutex;
	t_mutex		check_death_mutex;
	int			own_num;
	int			meal_count;
}				t_philo;

typedef struct s_data // info about all threads, mutexes and additional staff
{
	int64_t		time_to_die;
	int			each_must_eat;
	int			philo_num;
	t_fork		*forks;
	pthread_t	*thread_ids;
	t_philo		*philos;
	t_mutex		message_mutex;
}				t_data;

//main.c
// checking whether arguments are correct or not
int				check_args(int ac, char **av);

// init.c
// initialization of all necessary mutexes and creation of threads
int				init_phil_data(t_data *data, char **av);
int				init_data(t_data *data, int ac, char **av);
int				init_forks(t_data *data);

// philo.c
// locking/unlocking mutexes to put a message on a screen
// creating philos lifecycle in a main function
void			to_sleep(t_philo *philo);
void			to_eat(t_philo *philo);
void			*philosophers(void *arg);

// time.c
// checking time in mcs and return it in ms
int64_t			get_time_ms(void);

// lib_utils.c
// taking out integers, checking a negative sign, print a message 
// and free all allocated memory
int				ft_atoi(char *str);
int				if_sign(int ac, char **av);
void			print_message(t_philo *philo, char *msg);
void			free_all(t_data *data);

// philo_utils.c
// creation if threads, locking/unlocking mutexes, slowing down threads
int				create_threads(t_data *data);
void			take_forks(t_philo *philo);
void			ft_usleep(int64_t ms);
void			put_back_forks(t_philo *philo);

// destroy_mutexes.c
// checking for a dead mutex and detaching/joining threads
void			check_death(t_data *data);
int				is_dead(t_data *data, int i);
void			destroy_mutexes(t_data *data);

#endif