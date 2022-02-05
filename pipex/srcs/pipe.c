/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:55:28 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/05 21:54:16 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_exec(int fd1, char *cmd1, int *end, char **env)
{
	if (dup2(fd1, STDIN_FILENO) < 0) // we want f1 to be execve() input
	{
		// close everythng
		exit(1);
	}
	if (dup2(end[1], STDOUT_FILENO) < 0)
	{
		//close everything
		exit(1);
	}
	close(end[0]); // always close the end of the pipe you don't use
	close(fd1);

	char **argv;
	argv = ft_split(cmd1, ' '); // "ls -l" -> ["ls", "-l", NULL]

	char *path = "/bin/ls"; // to parse PATH from env
	//find_path(); // TODO: find PATH part with our cmd
	// strcat(path, argv[0]);

	execve(path, ++argv, env);
	
	exit(1);
}

void	child2_exec(int fd2, char *cmd2, int *end, char **env)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
	if (dup2(fd2, STDOUT_FILENO) < 0) // fd2 - output
	{
		// close everythng
		exit(1);
	}
	if (dup2(end[0], STDIN_FILENO) < 0) // end[0] - input
	{
		//close everything
		exit(1);
	}
	close(end[1]); // always close the end of the pipe you don't use
	close(fd2);

	char **argv;
	argv = ft_split(cmd2, ' '); // "ls -l" -> ["ls", "-l", NULL]

	char *path = "/bin/cat"; // to parse PATH from env
	//find_path(); // TODO: find PATH part with our cmd
	// strcat(path, argv[0]);

	execve(path, ++argv, env);
	
	exit(1);
}

void	pipex(int fd1, int fd2, char *cmd1, char *cmd2, char **env)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("child1 error "));
	if (child1 == 0)
		child1_exec(fd1, cmd1, end, env);
	child2 = fork();
	if (child2 < 0)
		return (perror("child2 error "));
	if (child2 == 0)
		child2_exec(fd2, cmd2, end, env);
	close(fd1);
	close(fd2);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	
}

int main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC | 0644);
	if (fd1 < 0 || fd2 < 0)
		return (-1);
	pipex(fd1, fd2, av[2], av[3], env);
	//os.system("ls -l");
	//execve("ls", ["-l"], ["...", "PATH=/bin/", "..."]);
}