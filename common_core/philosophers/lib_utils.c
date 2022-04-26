/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:43:29 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 16:39:00 by mgwyness         ###   ########.fr       */
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

int	if_sign(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (av[i][0] == '-')
			return (1);
		i++;
	}
	return (0);
}

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->message_mutex);
	if (msg)
	{
		printf("%lld %d %s\n", get_time_ms() - philo->start_time,
			philo->own_num + 1, msg);
		pthread_mutex_unlock(philo->message_mutex);
	}
	else
		printf("%lld %d %s\n", get_time_ms() - philo->start_time,
			philo->own_num + 1, "has died");
}

void	free_all(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data->thread_ids)
		free(data->thread_ids);
}
