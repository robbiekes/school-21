#include "philo.h"

// TODO: write your own usleep
// TODO: write is_dead() and print_message()

int	init_data(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->forks = (t_fork **)malloc(sizeof(t_fork *) * data->philo_num);
	if (!(data->forks))
		return (1);
	data->philos = (t_philo **)malloc(sizeof(t_philo *) * data->philo_num);
	if (!(data->philos))
		return (1);
	data->thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	if (!(data->thread_ids))
		return (1);
}

int	init_phil_data(t_data *data, int ac, char **av)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		data->philos[i] = (t_philo *)malloc(sizeof(t_philo));
		data->philos[i]->own_num = i;
		if (!(data->philos[i]))
			return (1);
		data->philos[i]->time_to_die = (unsigned int)ft_atoi(av[2]);
		data->philos[i]->time_to_eat = (unsigned int)ft_atoi(av[3]);
		data->philos[i]->time_to_sleep = (unsigned int)ft_atoi(av[4]);
		data->philos[i]->left = data->forks[(i + (data->philo_num - 1)) % data->philo_num];
		data->philos[i]->right = data->forks[i];
		data->philos[i]->last_meal = 0;
		if (ac == 6)
			data->philos[i]->each_must_eat = ft_atoi(av[5]);
		else
			data->philos[i]->each_must_eat = -1;
		data->philos[i]->must_die = 0;
		//data->philos[i]->write_mutex = 0;
	}
	return (0);
}

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		free(data->forks[i]);
		free(data->philos[i]);
	}
	free(data->forks);
	free(data->philos);
	free(data->thread_ids);
}

unsigned int	get_time_ms(void)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, 0);
	return (cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000);
}

int	create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		data->thread_ids[i] = 0;
	i = -1;
	while (++i < data->philo_num)
	{
		data->philos[i]->start_time = get_time_ms();
		data->philos[i]->last_meal = get_time_ms();
		if (pthread_create(&(data->thread_ids[i]), 0, philosophers, data->philos[i]))
		{
			i = -1;
			data->philos[i]->must_die = 1;
			while (data->thread_ids[++i])
				pthread_join(data->thread_ids[i], 0);
			free_all(data);
			return (1);
		}
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->philo_num)
	{
		data->forks[i] = (t_fork *)malloc(sizeof(t_fork));
		if (!(data->forks[i]))
			return (1);
		data->forks[i]->num = i;
		if (pthread_mutex_init(&(data->forks[i]->mutex), 0))
			return (1);
	}
}

int	is_dead(t_philo *philo);

void	print_message(t_philo *philo, char *str);

void take_forks(t_philo *philo)
{
	if (philo->left->num < philo->right->num)
	{
		pthread_mutex_lock(&(philo->left->mutex), 0);
		print_message(philo, EAT_MSG);
		if (is_dead(philo))
			return ;
	}
	pthread_mutex_lock(&(philo->right->mutex)), 0);
	print_message(philo, EAT_MSG);
	if (is_dead(philo))
			return ;
	if (philo->left->num > philo->right->num)
	{
		pthread_mutex_lock(&(philo->left->mutex), 0);
		print_message(philo, EAT_MSG);
		if (is_dead(philo))
			return ;
	}
}

void	sleep(t_philo *philo)
{
	if (!(*(philo->must_eat)))
	{
		print_message(philo, EAT_MSG);
		usleep(philo->time_to_sleep);
		if (is_dead(philo))
			return ;
		print_message(philo, SLEEP_MSG);
	}
}

void	put_back_forks(t_philo *philo)
{

}

void	*philosophers(void *arg)
{
	t_philo	*one_philo;
	int		i;

	one_philo = (t_philo *) arg;
	usleep(100);
	while (!(*(one_philo->must_die)))
	{
		
	}
	//philo comes to table and sleep() for time_to_sleep ms
	take_forks(one_philo);
	// 1. take_forks() (== pthread_mutex_lock()) & print_message(eat) - check
	sleep(one_philo);
	// 2. sleep() for time_to_eat ms & print_message(sleep)
	put_back_forks(one_philo);
	// 3. put_back_forks() (== pthread_mutex_unlock()) & print_message(put back fork)
	// 4. sleep() for time_to_eat ms & print_message(sleep)
	// if philo-1 and philo+1 didn't eat and 
}
