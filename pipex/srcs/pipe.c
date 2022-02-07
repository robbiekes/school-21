/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:55:28 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/07 20:51:27 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**set_args(char *cmd) // argv = ["pipex", "-c", cmd, NULL]
{
	char **argv;
	argv = (char **)malloc(sizeof(char *) * 4);
	argv[0] = ft_strdup("pipex");
	argv[1] = ft_strdup("-c");
	argv[2] = cmd;
	argv[3] = 0;
	return (argv);
}
void	input_exec(int fd1, char *cmd1, int *end, char **env)
{
	char **args;
	const char	*path = "/bin/bash";
	
	args = set_args(cmd1);
	if (dup2(fd1, STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(1);
	}
	close(end[0]); // always close the end of the pipe you don't use
	close(fd1);

	execve(path, args, env);
	
	exit(1);
}

void	output_exec(int fd2, char *cmd2, int *end, char **env)
{
	char **args;
	const char	*path = "/bin/bash";
	
	args = set_args(cmd2);
	if (dup2(fd2, STDOUT_FILENO) < 0 || dup2(end[0], STDIN_FILENO) < 0)
	{
		perror("dup2");
		exit(1);
	}
	close(end[1]); // always close the end of the pipe you don't use
	close(fd2);

	execve(path, args, env);
	
	exit(1);
}

void	pipex(int fd1, int fd2, char *cmd1, char *cmd2, char **env)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end))
		return (perror("pipe error"));
	child1 = fork();
	if (child1 < 0)
		return (perror("child1 error "));
	if (child1 == 0)
		input_exec(fd1, cmd1, end, env);
	child2 = fork();
	if (child2 < 0)
		return (perror("child2 error "));
	if (child2 == 0)
		output_exec(fd2, cmd2, end, env);
	close(end[0]);
	close(end[1]);
	waitpid(child2, &status, 0);
	waitpid(child1, &status, 0);
}

int main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC | 0644);
	if (fd1 < 0 || fd2 < 0)
		exit(2);
	pipex(fd1, fd2, av[2], av[3], env);
	return (0);
}
