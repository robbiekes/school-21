/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaira <zaira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:55:28 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/03 18:55:44 by zaira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int pipe(int fifo[2])
// {
	
// }
int ffork()
{
	pid_t	id;
	id = fork();
	if (id == -1)
	{
		perror("fork error");
		return (0);	
	}
	else if (id == 0)
		printf("child process  created\n");
	else
		printf("parent process after work\n");
	return (id);
}

int	wwaitpid()
{
	pid_t	child_pid;
	pid_t	pid;
	int	status;
	pid = 0;
	status = 0;
	child_pid = ffork();
	pid = waitpid(child_pid, &status, WUNTRACED);
	printf("[%d]\n", child_pid);
	if (WIFEXITED(status))
	{
		write(2, &child_pid, 1);
		printf("exits: %d\n", WEXITSTATUS(status));
	}
	else if (WIFSTOPPED(status))
	{
		write(2, &child_pid, 1);
		printf("stopped by: %d\n", WSTOPSIG(status));
	}
	else if (WIFSIGNALED(status))
	{
		write(2, &child_pid, 1);
		printf("killed by: %d\n", WTERMSIG(status));
	}
	else
	{
		perror("waitpid error\n");
		exit(0);
	}
	return (0);
}

int	ppipe()
{
	pid_t	child_pid;
	int		fifo[2];
	int		status;
	char	buf[80];

	if (pipe(fifo) == -1)
	{
		perror("pipe");
		exit(1);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(2);
	}
	else if (child_pid == 0)
	{
		close(fifo[0]); // child process
		write(fifo[1], "child executed\n", 14);
		close(fifo[1]);
		exit(0);
	}
	close (fifo[1]); // parent process
	read(fifo[0], buf, 80);
	printf("%s\n", buf);
	close (fifo[0]);
	wait(0);
	// if (waitpid(child_pid, &status, 0) == child_pid && WIFEXITED(status))
	// 	return (WEXITSTATUS(status));
	return (3);
}

int	redirection()
{
	int	fd;
	int	fd2;

	if (fork())
	{
		fd = open("src_file", O_RDONLY);
		fd2 = open("dst_file", O_WRONLY, O_CREAT, O_TRUNC);
		if (fd == -1 || fd2 == -1)
		{
			perror("open error");
			exit(1);
		}
		dup2(fd, STDIN_FILENO);
		if (dup2 == -1)
			exit(5);
		dup2(fd2, STDOUT_FILENO);
		if (dup2 == -1)
			exit(6);
		close(fd);
		close(fd2);
		execlp("sort", "sort", 0);
		exit(8);
	}
	return (0);
}

int main()
{
	// ffork();
	// ppipe();
	wwaitpid();
}