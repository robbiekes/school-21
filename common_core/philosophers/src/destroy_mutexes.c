/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:39:25 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 16:06:57 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->philos[i].check_death_mutex);
	if ((int64_t)get_time_ms() - data->philos[i].last_meal > data->time_to_die)
	{
		print_message(data->philos + i, 0);
		return (1);
	}
	pthread_mutex_unlock(&data->philos[i].check_death_mutex);
	return (0);
}

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_detach(data->thread_ids[i]);
	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->philos[i].check_death_mutex);
		pthread_mutex_destroy(&(data->forks[i].mutex));
		pthread_mutex_destroy(&(data->message_mutex));
	}
}

void	check_death(t_data *data)
{
	int	i;
	int	all_ate;

	while (1)
	{
		i = -1;
		all_ate = 1;
		while (++i < data->philo_num)
		{
			if (!data->each_must_eat || \
				data->philos[i].meal_count < data->each_must_eat)
				all_ate = 0;
			if (is_dead(data, i))
			{
				destroy_mutexes(data);
				return ;
			}
		}
		if (all_ate)
		{
			destroy_mutexes(data);
			return ;
		}
		usleep(250);
	}
}
