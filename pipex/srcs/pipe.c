/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:55:28 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/02 19:54:28 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int pipe(int fifo[2])
// {
	
// }

int	main()
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
