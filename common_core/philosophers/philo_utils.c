/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:58:34 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 16:36:41 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (pthread_create(&(data->thread_ids[i]), 0, philosophers,
				data->philos + i))
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

void	put_back_forks(t_philo *philo)
{
	if (philo->left->num > philo->right->num)
		pthread_mutex_unlock(&(philo->left->mutex));
	pthread_mutex_unlock(&(philo->right->mutex));
	if (philo->left->num < philo->right->num)
		pthread_mutex_unlock(&(philo->left->mutex));
}

void	take_forks(t_philo *philo)
{
	if (philo->left->num <= philo->right->num)
	{
		pthread_mutex_lock(&(philo->left->mutex));
		print_message(philo, FORK_MSG);
	}
	pthread_mutex_lock(&(philo->right->mutex));
	print_message(philo, FORK_MSG);
	if (philo->left->num >= philo->right->num)
	{
		pthread_mutex_lock(&(philo->left->mutex));
		print_message(philo, FORK_MSG);
	}
}

void	ft_usleep(int64_t ms)
{
	int64_t	current_time;
	int64_t	start_sleeping;

	current_time = get_time_ms();
	start_sleeping = current_time;
	while (current_time - start_sleeping < ms)
	{
		usleep(500);
		current_time = get_time_ms();
	}
}
