#include "philo.h"

int	init_forks(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->philo_num)
	{
		data->forks[i].num = i;
		if (pthread_mutex_init(&(data->forks[i].mutex), 0))
			return (1);
	}
}

int	init_data(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->philo_num);
	if (!(data->forks))
		return (1);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
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
		data->philos[i].own_num = i;
		data->philos[i].time_to_die = (unsigned int)ft_atoi(av[2]);
		data->philos[i].time_to_eat = (unsigned int)ft_atoi(av[3]);
		data->philos[i].time_to_sleep = (unsigned int)ft_atoi(av[4]);
		data->philos[i].left = data->forks + (i + (data->philo_num - 1)) % data->philo_num;
		data->philos[i].right = data->forks + i;
		data->philos[i].last_meal = 0;
		data->philos[i].meal_count = 0;
		if (ac == 6)
			data->philos[i].each_must_eat = ft_atoi(av[5]);
		else
			data->philos[i].each_must_eat = -1;
		data->philos[i].message_mutex = 0;
	}
	return (0);
}

