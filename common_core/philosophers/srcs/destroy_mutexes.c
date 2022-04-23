#include "philo.h"

void	check_death(t_data *data) //////////
{
	int	i;

	i = -1;
	while (i < data->philo_num)
	{
		if (is_dead(data->philos[i]))
		{
			destroy_mutexes(data);
			free_all(data);
		}
	}
}

void	destroy_mutexes(t_data *data) ///////////
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_destroy(&(data->forks[i]));
	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&(data->philos[i].message_mutex));
		pthread_mutex_destroy(&(data->philos[i].left));
		pthread_mutex_destroy(&(data->philos[i].right));
	}
}
