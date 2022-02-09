/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:55:28 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/09 18:57:55 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	free_struct(char **args)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < 4)
// 	{
// 		free(args[i]);
// 		i++;
// 	}
// 	free(args);
// }

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

void	input_exec(int fd1, char *cmd1, int *tube, char **env)
{
	char		**args;
	const char	*path = "/bin/bash";

	args = set_args(cmd1);
	if (dup2(fd1, STDIN_FILENO) < 0 || dup2(tube[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(1);
	}
	// free_struct(args);
	close(tube[0]);
	close(fd1);
	execve(path, args, env);
	exit(1);
}

void	output_exec(int fd2, char *cmd2, int *tube, char **env)
{
	char		**args;
	const char	*path = "/bin/bash";

	args = set_args(cmd2);
	if (dup2(fd2, STDOUT_FILENO) < 0 || dup2(tube[0], STDIN_FILENO) < 0)
	{
		perror("dup2");
		exit(1);
	}
	close(tube[1]);
	close(fd2);
	execve(path, args, env);
	exit(1);
}

void	pipex(int fd1, int fd2, char **args, char **env)
{
	int		tube[2];
	pid_t	child1;
	pid_t	child2;

	if (pipe(tube))
		return (perror("pipe"));
	child1 = fork();
	if (child1 < 0)
		return (perror(args[2]));
	if (child1 == 0)
		input_exec(fd1, args[2], tube, env);
	child2 = fork();
	if (child2 < 0)
		return (perror(args[3]));
	if (child2 == 0)
		output_exec(fd2, args[3], tube, env);
	close(tube[0]);
	close(tube[1]);
	waitpid(-1, 0, 0);
	waitpid(-1, 0, 0);
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;

	if (ac == 5)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC | 0644);
		if (fd1 < 0)
		{
			perror(av[1]);
			exit(2);
		}
		else if ( fd2 < 0)
		{
			perror(av[4]);
			exit(2);
		}
		pipex(fd1, fd2, av, env);
	}
	else
		write(2, "Invalid number of arguments\n", 29);
	return (0);
}
