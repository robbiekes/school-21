/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:55:51 by mgwyness          #+#    #+#             */
/*   Updated: 2022/04/26 12:46:18 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	if (if_sign(ac, av))
	{
		write(2, "Error: invalid argument\n", 24);
		return (1);
	}
	if (ac != 6 && ac != 5)
	{
		write(2, "Error: invalid number of arguments\n", 35);
		return (1);
	}
	if (ac == 6 && ft_atoi(av[5]) == 0)
	{
		write(2, "Error: philosophers must eat at least one time\n", 47);
		return (1);
	}
	if (ft_atoi(av[1]) < 1)
	{
		write(2, "Error: not enough philosophers\n", 31);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av))
		return (1);
	if (init_data(&data, ac, av))
		return (1);
	if (init_phil_data(&data, av))
		return (1);
	if (init_forks(&data))
		return (1);
	if (create_threads(&data))
		return (1);
	check_death(&data);
	free_all(&data);
	return (0);
}
