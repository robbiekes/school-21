/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:43:47 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 12:43:48 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	get_time_ms(void)
{
	struct timeval	cur_time;

	gettimeofday(&cur_time, 0);
	return (cur_time.tv_sec * 1000 + cur_time.tv_usec / 1000);
}
