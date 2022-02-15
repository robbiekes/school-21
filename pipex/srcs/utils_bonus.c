/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:08:48 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/15 20:30:35 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	perror_exit(char *message)
{
	perror(message);
	exit(1);
}

void	init_data(t_data *data, int ac, char **av, char **env)
{
	data->ac = ac;
	data->env = env;
	data->av = av;
	data->limiter = 0;
	if (!ft_strcmp(av[1], "here_doc"))
	{
		data->limiter = av[2];
		get_input(data);
	}
	else
	{
		data->fd1 = open(av[1], O_RDONLY);
		if (data->fd1 < 0)
			perror_exit(av[1]);
	}
	data->fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->fd2 < 0)
		perror_exit(av[ac - 1]);
}
