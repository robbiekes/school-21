/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:43:29 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/24 02:22:33 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	ans;

	i = 0;
	ans = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') * (-1) + (str[i] == '+');
		i++;
	}
	while (str[i] == '0')
		i++;
	if (str[i] > '0' && str[i] <= '9')
		ans = sign * (str[i++] - '0');
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((ans * 10 + sign * (str[i] - '0') > 0) != (ans > 0))
			return (0);
		ans = ans * 10 + sign * (str[i] - '0');
		i++;
	}
	return (ans);
}

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->message_mutex));
	printf("%d\n", msg);
}

void	ft_usleep(unsigned int ms)
{
	unsigned int	current_time;
	unsigned int	start_sleeping;

	current_time = get_time_ms();
	start_sleeping = current_time;
	while (current_time - start_sleeping < ms)
	{
		usleep(100); // 1/10 ms
		current_time = get_time_ms();
	}
}

void	free_all(t_data *data) //////////////
{
	free(data->forks);
	free(data->philos);
	free(data->thread_ids);
}
