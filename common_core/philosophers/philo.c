#include "philo.h"

// написать ft_atoi()
typedef struct s_data 
{
	int philo_num; // == num of threads
	int time_to_eat; //in ms
	int time_to_die; //in ms
	int time_to_sleep; //in ms
	int *min;
	int *max;

} t_data;

void	data_init(t_data *data, char **av, int *id)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->philo_num = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
}

void *ft_philo(t_data *data)
{
	///
}

int main(int ac, char **av)
{
	t_data	*data;
	pthread_t id;
	int		i;

	i = -1;
	data_init(data, av, &id);

	while (++i < data->philo_num) // создание потоков (философов)
		pthread_create(&id, 0, ft_philo, data);

	i = -1;
	while (++i < data->philo_num)
	{
		// проверка на то, не умер ли какой-либо философ
		// если умер, return (0)
	}

	free(data);
	return (0);
	
}