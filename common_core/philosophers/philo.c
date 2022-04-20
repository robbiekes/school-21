#include "philo.h"

// TODO: add ft_atoi()


int	init_data(t_data *data, ) // malloc philos, threads and so on

int	init_phil_data(t_philo **philo, int ac, char **av)
{
	*philo = (t_philo *)malloc(sizeof(t_philo));
	if (!*philo)
		return (1);
	(*philo)->philo_num = ft_atoi(av[1]);
	if ((*philo)->philo_num < 1) // ONE OR MORE philosophers sit at a round table
	{
		free(*philo);
		return (1);
	}
	(*philo)->time_to_die = ft_atoi(av[2]);
	(*philo)->time_to_eat = ft_atoi(av[3]);
	(*philo)->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		(*philo)->each_must_eat = ft_atoi(av[5]);
	(*philo)->must_die = 0;
	return (0);
}


int	init_threads(t_philo *philo, p_data *data)
{
	int			i;
	pthread_t	id;
	pthread_t	*thread_ids;


	i = -1;
	thread_ids = (pthread_t *)malloc(sizeof(pthread_t) * philo->philo_num);
	if (!thread_ids)
		return (1);
	while (++i < philo->philo_num)
		thread_ids[i] = 0;
	i = -1;
	while (++i < philo->philo_num)
	{
		if (pthread_create(&id, 0, philosophers, philo))
		{
			i = -1;
			philo->must_die = 1;
			while (thread_ids[++i])
				pthread_join(thread_ids[i], 0);
			free(thread_ids);
			free(philo);
			return (1);
		}
	}
	return (0);
}

int	init_forks(p_data *data) // aka forks (== philo_num)
{
	int		i;

	i = -1;
	data->forks = (p_mutex *)malloc(sizeof(p_mutex));
	if (!data->forks)
		return (1);
	while (++i < data->philo->philo_num)
		pthread_mutex_init(&(data->forks[i]), 0);
}

void	*philosophers(void *arg)
{
	t_philo *philo = (t_philo *) arg;
	// if philo-1 and philo+1 didn't eat and 
}

int check_args(int ac, char **av)
{
	if (ac > 6 || ac < 5)
	{
		write(2, "Not enough arguments\n", 21);
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

	if (init_phil_data(&philo, ac, av))
		return (1);

	if (init_forks(philo))
		return (1);

	if (init_threads(data, philo))
		return (1);

	i = -1;
	while (++i < philo->philo_num)
		pthread_join(&(data->thread_ids[i]), 0);

	free(philo);
	free(data);
	return (0);
	
}