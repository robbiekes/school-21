#include "philo.h"

// TODO: add ft_atoi()


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

int	init_forks(t_data *data) // aka forks (== philo_num)
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

void	*philosophers(void *arg)
{
	t_philo	*one_philo;
	int		i;

	one_philo = (t_philo *)arg;
	//philo comes to table and sleep() for time_to_sleep ms
	// 1. take_forks() (== pthread_mutex_lock()) & print_message(eat)
	// 2. sleep() for time_to_eat ms & print_message(sleep)
	// 3. put_back_forks() (== pthread_mutex_unlock()) & print_message(put back fork)
	// 4. sleep() for time_to_eat ms & print_message(sleep)
	// if philo-1 and philo+1 didn't eat and 
}

int check_args(int ac, char **av)
{
	if (ac > 6 || ac < 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (1);
	}
	if (ft_atoi(av[1]) < 1) // ONE OR MORE philosophers sit at a table
	{
		write(2, "Not enough philosophers\n", 24);
		return (1);
	}
}

int main(int ac, char **av)
{
	int		i;
	t_philo	*philo;
	t_data	*data;
	
	if (check_args(ac, av))
		return (1);

	if (init_data(data, ac, av))
		return (1);

	if (init_phil_data(data, ac, av))
		return (1);

	if (init_threads(data))
		return (1);

	if (init_forks(philo))
		return (1);

	

	i = -1;
	while (++i < philo->philo_num)
		pthread_join(&(data->thread_ids[i]), 0);

	free(philo);
	free(data);
	return (0);
	
}