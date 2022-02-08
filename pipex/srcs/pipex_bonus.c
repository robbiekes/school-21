/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:51 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/08 20:16:14 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex_advanced(int ac, char **av, t_data *file_data)
{
	int	i;
	int	pipe_count;
	static int	tube[2][2] = {-1, -1, -1, -1};
	
	i = 3;
	pipe_count = 0;
	while (i < ac)
	{
		if (pipe(tube[pipe_count]))
			return (perror("pipe"));
		
	}
}

int	main(int ac, char **av, char **env)
{
	t_data *file_data;
	
	file_data = (t_data *)malloc(sizeof(t_data));
	file_data->fd1 = 0;
	file_data->fd2 = 0;
	if (ac >= 5)
	{
		file_data->fd1 = open(av[1], O_RDONLY);
		file_data->fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC | 0644);
		if (file_data->fd1 < 0)
		{
			perror(av[1]);
			exit(2);
		}
		else if (file_data->fd2 < 0)
		{
			perror(av[4]);
			exit(2);
		}
		pipex_advanced(ac, av, file_data);
	}
	else
		write(2, "Invalid number of arguments\n", 29);
	exit(0);
}