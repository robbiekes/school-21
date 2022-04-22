#include "philo.h"

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
