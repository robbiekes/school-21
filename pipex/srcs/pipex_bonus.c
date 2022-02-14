/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:51 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/14 19:35:12 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**set_args(char *cmd)
{
	char	**argv;

	argv = (char **)malloc(sizeof(char *) * 4);
	if (argv == 0)
		exit(1);
	argv[0] = ft_strdup("pipex");
	argv[1] = ft_strdup("-c");
	argv[2] = cmd;
	argv[3] = 0;
	return (argv);
}

void	perror_exit(char *message)
{
	perror(message);
	exit(1);
}

void	child_exec(t_data *data, int i)
{
	char		**args;
	const char	*path = "/bin/bash";

	args = set_args(data->av[i]);
	if (i == 2)
	{
		if (dup2(data->fd1, 0) < 0 || dup2(data->tube2[1], 1) < 0)
			perror_exit("dup2");
	}
	else if (i == data->ac - 2)
	{
		if (dup2(data->tube1[0], 0) < 0 || dup2(data->fd2, 1) < 0)
			perror_exit("dup2");
	}
	else
	{
		if (dup2(data->tube1[0], 0) < 0 || dup2(data->tube2[1], 1) < 0)
		{
			write(1, "55\n", 3);
			perror_exit("dup2");
		}
	}
	close(data->tube1[0]);
	close(data->tube1[1]);
	execve(path, args, data->env);
	exit(0);
}

int	pipex_advanced(t_data *data)
{
	int	i;
	int	status;
	int	child_proc;

	i = 2 + (data->limiter != 0);
	while (i < data->ac - 1)
	{
		if (pipe(data->tube2))
			perror_exit("pipe");
		child_proc = fork();
		if (child_proc < 0)
			perror_exit(data->av[i]);
		if (child_proc == 0)
			child_exec(data, i);
		close(data->tube1[0]);
		close(data->tube1[1]);
		data->tube1[0] = data->tube2[0];
		data->tube1[1] = data->tube2[1];
		i++;
	}
	while (i-- > 2)
		waitpid(-1, &status, 0);
	return (status);
}

void	get_input(t_data *data)
{
	char	*line;
	
	if (pipe(data->tube1))
		perror_exit("pipe");
	line = get_next_line(0);
	while (ft_strcmp(line, data->limiter) != 10) // 10 == \n
	{
		write(data->tube1[1], line, ft_strlen(line));
		free(line);
		line = 0;
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;
	int		status;
	
	status = 1;
	if (ac >= 5)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (data == 0)
			return (0);
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
		status = pipex_advanced(data);
		close(data->fd1);
		close(data->fd2);
		free(data);
	}
	else
		write(2, "Invalid number of arguments\n", 29);
	return (status);
}
