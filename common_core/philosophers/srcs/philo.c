#include "philo.h"

int	create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		data->thread_ids[i] = 0;
	i = -1;
	while (++i < data->philo_num)
	{
		data->philos[i].start_time = get_time_ms();
		data->philos[i].last_meal = get_time_ms();
		if (pthread_create(&(data->thread_ids[i]), 0, philosophers, data->philos + i))
		{
			i = -1;
			while (data->thread_ids[++i])
				pthread_join(data->thread_ids[i], 0);
			free_all(data);
			return (1);
		}
	}
	return (0);
}

void take_forks(t_philo *philo)
{
	if (philo->left->num < philo->right->num)
	{
		pthread_mutex_lock(&(philo->left->mutex));
		print_message(philo, FORK_MSG);
	}
	pthread_mutex_lock(&(philo->right->mutex));
	print_message(philo, FORK_MSG);
	if (philo->left->num > philo->right->num)
	{
		pthread_mutex_lock(&(philo->left->mutex));
		print_message(philo, FORK_MSG);
	}
}

void	put_back_forks(t_philo *philo)
{
	if (philo->left->num > philo->right->num)
		pthread_mutex_unlock(&(philo->left->mutex));
	pthread_mutex_unlock(&(philo->right->mutex));
	if (philo->left->num < philo->right->num)
		pthread_mutex_unlock(&(philo->left->mutex));
}

void	to_sleep(t_philo *philo)
{
	print_message(philo, SLEEP_MSG);
	ft_usleep(philo->time_to_sleep);
}

void	to_eat(t_philo *philo) ///////////////////
{
	take_forks(philo);
	print_message(philo, EAT_MSG);
	philo->last_meal = get_time_ms();
	philo->meal_count++;
	ft_usleep(philo->time_to_eat);
	put_back_forks(philo);
}

void	*philosophers(void *arg)
{
	t_philo	*one_philo;

	one_philo = (t_philo *) arg;
	if (one_philo->own_num % 2)
		ft_usleep(one_philo->time_to_eat * 1000);
	while (1)
	{
		to_eat(one_philo);
		to_sleep(one_philo);
		print_message(one_philo, THINK_MSG);
	}
	return (0);
}
