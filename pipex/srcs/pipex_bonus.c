/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:51 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/09 19:13:34 by mgwyness         ###   ########.fr       */
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
		if (dup2(data->fd1, STDIN_FILENO) < 0 || dup2(data->tube2[1], STDOUT_FILENO) < 0)
			perror_exit("dup2");
	}
	if (i == data->ac - 2)
	{
		if (dup2(data->tube1[0], STDIN_FILENO) < 0 || dup2(data->fd2, STDOUT_FILENO) < 0)
			perror_exit("dup2");
	}
	else
	{
		if (dup2(data->tube1[0], STDIN_FILENO) < 0 || dup2(data->tube2[1], STDOUT_FILENO) < 0)
			perror_exit("dup2");
	}
	close(data->tube1[0]);
	close(data->tube1[1]);
	execve(path, args, data->env);
	exit(0);
}

void	pipex_advanced(t_data *data)
{
	int	i;
	int	child_proc;
	
	i = 2;
	child_proc = 0;
	while (i < data->ac - 1)
	{
		if (pipe(data->tube2))
			return (perror("pipe"));
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
		waitpid(-1, 0, 0);
}

int main(int ac, char **av, char **env)
{
	t_data *data;

	if (ac == 5)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (data == 0)
			return (0);
		data->ac = ac;
		data->env = env;
		data->av = av;
		data->fd1 = open(av[1], O_RDONLY);
		data->fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC | 0644);
		if (data->fd1 < 0)
			perror_exit(av[1]);
		else if (data->fd2 < 0)
			perror_exit(av[ac - 1]);
		// if (pipe(data->tube[0]))
		// 	return (perror("pipe"));
		pipex_advanced(data);
		close(data->fd1);
		close(data->fd2);
		free(data);
	}
	else
		write(2, "Invalid number of arguments\n", 29);
	return (0);
}






// int	pipex_advanced(int ac, char **av, t_data *file_data)
// {
// 	int	i;
// 	int	pipe_count;
// 	static int	tube[2][2] = {-1, -1, -1, -1};
	
// 	i = 3;
// 	pipe_count = 0;
// 	while (i < ac)
// 	{
// 		if (pipe(tube[pipe_count]))
// 			return (perror("pipe"));
		
// 	}
// }

// int	main(int ac, char **av, char **env)
// {
// 	t_data *file_data;
	
// 	file_data = (t_data *)malloc(sizeof(t_data));
// 	file_data->fd1 = 0;
// 	file_data->fd2 = 0;
// 	if (ac >= 5)
// 	{
// 		file_data->fd1 = open(av[1], O_RDONLY);
// 		file_data->fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC | 0644);
// 		if (file_data->fd1 < 0)
// 		{
// 			perror(av[1]);
// 			exit(2);
// 		}
// 		else if (file_data->fd2 < 0)
// 		{
// 			perror(av[4]);
// 			exit(2);
// 		}
// 		pipex_advanced(ac, av, file_data);
// 	}
// 	else
// 		write(2, "Invalid number of arguments\n", 29);
// 	exit(0);
// }