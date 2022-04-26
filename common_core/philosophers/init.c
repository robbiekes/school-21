/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:40:18 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 16:38:40 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		data->forks[i].num = i;
		if (pthread_mutex_init(&(data->forks[i].mutex), 0))
			return (1);
	}
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = (int64_t)ft_atoi(av[2]);
	data->each_must_eat = 0;
	if (ac == 6)
		data->each_must_eat = ft_atoi(av[5]);
	data->forks = (t_fork *)malloc(sizeof(t_fork) * data->philo_num);
	if (!(data->forks))
		return (1);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	if (!(data->philos))
		return (1);
	data->thread_ids = (pthread_t *)malloc(sizeof(pthread_t)
			* data->philo_num);
	if (!(data->thread_ids))
		return (1);
	if (pthread_mutex_init(&(data->message_mutex), 0))
		return (1);
	return (0);
}

int	init_phil_data(t_data *data, char **av)
{
	int				i;
	const int64_t	start_time = get_time_ms();
	const int64_t	time_to_eat = (int64_t)ft_atoi(av[3]);
	const int64_t	time_to_sleep = (int64_t)ft_atoi(av[4]);

	i = -1;
	while (++i < data->philo_num)
	{
		data->philos[i].own_num = i;
		data->philos[i].time_to_eat = time_to_eat;
		data->philos[i].time_to_sleep = time_to_sleep;
		data->philos[i].left = data->forks + (i + (data->philo_num - 1))
			% data->philo_num;
		data->philos[i].right = data->forks + i;
		data->philos[i].start_time = start_time;
		data->philos[i].last_meal = start_time;
		data->philos[i].meal_count = 0;
		data->philos[i].message_mutex = &data->message_mutex;
		if (pthread_mutex_init(&data->philos[i].check_death_mutex, 0))
			return (1);
	}
	return (0);
}
