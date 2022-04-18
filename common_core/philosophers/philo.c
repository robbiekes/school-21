#include "philo.h"

// написать ft_atoi()

void	init_args(t_data *data, char **av)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->philo_num = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
}

void	init_philos(t_data *data);

void	init_threads(t_data *data);

void	init_mutex(t_data *data);

int main(int ac, char **av)
{
	t_data	*data;

	init_args(data, av);
	//init_philos(data);
	//init_threads(data);
	//init_mutex(data);

	while (++i < data->philo_num) // проверка на то, не умер ли какой-либо философ
	// если умер, return (0)

	free(data);
	return (0);
	
}