#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int main(int ac, char **av, char **env)
{
	int i = 0;
	int pid = 0;
	int tube[2];
	int tmp_fd = dup(STDIN_FILENO);
	(void)ac;

	while (av[i] && av[i + 1])
	{
		i = 0;
		av = &av[i + 1];
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (!strcmp(av[0], "cd"))
		{
			if (i != 2)
				ft_putstr("error: cd: bad arguments\n");
			else if (chdir(av[1]))
			{
				ft_putstr("error: cd: cannot change directory to ");
				ft_putstr(av[1]);
				write(2, "\n", 1);
			}
		}
		else if (i != 0 || (av[i] == NULL && !strcmp(av[i], ";")))
		{
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				close(tmp_fd);
				if (ft_execve(av, i, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				while (waitpid(-1, 0, 2) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
	}
}