/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:51 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/15 20:39:37 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**set_args(char *cmd)
{
	char	**argv;

	argv = (char **)malloc(sizeof(char *) * 4);
	if (argv == 0)
		exit(EXIT_FAILURE);
	argv[0] = ft_strdup("pipex");
	argv[1] = ft_strdup("-c");
	argv[2] = cmd;
	argv[3] = 0;
	return (argv);
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
			perror_exit("dup2");
	}
	close(data->tube1[0]);
	close(data->tube1[1]);
	execve(path, args, data->env);
	exit(0);
}

int	pipex_advanced(t_data *data, int *pids) // has more than 25 lines !!!!!!!!!!!!!!!!!
{
	int	i;
	// int	status;
	int	error_code;
	int b =  0;
	int	child_proc;

	error_code = 0;
	i = 2 + (data->limiter != 0);
	while (i < data->ac - 1)
	{
		if (pipe(data->tube2))
			perror_exit("pipe");
		child_proc = fork();
		pids[b] = child_proc;
		printf("%d\n", pids[b]);
		if (child_proc < 0)
			perror_exit(data->av[i]);
		if (child_proc == 0)
			child_exec(data, i);
		close(data->tube1[0]);
		close(data->tube1[1]);
		data->tube1[0] = data->tube2[0];
		data->tube1[1] = data->tube2[1];
		i++;
		b++;
	}
	// printf("%d\n", b);
	// waitpid(0, &status, 0);
	// if (status != 0)
	// 	error_code = status;
	// printf("%d %d %d %d", pids[0], pids[1], pids[2], pids[3]);
	// while (b-- > 0)
	// {
	// 	waitpid(pids[b], &status, 0);
	// 	if (status != 0)
	// 		error_code = status;
	// }
	return (error_code);
}

void	get_input(t_data *data)
{
	char	*line;

	if (pipe(data->tube1))
		perror_exit("pipe");
	line = get_next_line(0);
	while (ft_strcmp(line, data->limiter) != 10)
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
	int		*fork_pids;
	int		status;

	status = 1;
	if (ac >= 5)
	{
		data = (t_data *)malloc(sizeof(t_data));
		fork_pids = (int *)malloc(sizeof(int) * ac - 3);
		if (data == 0)
			return (0);
		init_data(data, ac, av, env);
		status = pipex_advanced(data, fork_pids);
		close(data->fd1);
		close(data->fd2);
		free(data);
		free(fork_pids);
	}
	else
		write(2, "Invalid number of arguments\n", 29);
	return (status);
}
