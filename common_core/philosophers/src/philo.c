/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:43:36 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 16:06:09 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	to_sleep(t_philo *philo)
{
	print_message(philo, SLEEP_MSG);
	ft_usleep(philo->time_to_sleep);
}

void	to_eat(t_philo *philo)
{
	take_forks(philo);
	print_message(philo, EAT_MSG);
	pthread_mutex_lock(&philo->check_death_mutex);
	philo->last_meal = get_time_ms();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->check_death_mutex);
	ft_usleep(philo->time_to_eat);
	put_back_forks(philo);
}

void	*philosophers(void *arg)
{
	t_philo	*one_philo;

	one_philo = (t_philo *) arg;
	if (one_philo->own_num % 2)
		ft_usleep(one_philo->time_to_eat / 2);
	while (1)
	{
		to_eat(one_philo);
		to_sleep(one_philo);
		print_message(one_philo, THINK_MSG);
	}
	return (0);
}
