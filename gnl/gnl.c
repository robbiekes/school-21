#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_buf(int fd, char *reserved)
{
	int		count;
	char	*buf;
	int		i;

	count = 0;
	i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	while (!ft_strchr(reserved, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
		{
			free(buf);
			return (0);
		}
		reserved = ft_strjoin(reserved, buf);
		printf("%s\n", reserved);
	}
	free(buf);
	return (reserved);
}

char *ft_create_line(char *reserved)
{
	char	*one_line;

	if (reserved[0] == '\0')
		return (0);
	one_line = ft_strdup(reserved);
	//printf("(37) %s\n", one_line);
	free(reserved);
	return (one_line);
}

char *ft_gnl(fd)
{
	static char *reserved;
	char *one_line;

	if (fd < 0)
		return (0);
	reserved = ft_read_buf(fd, reserved);
	one_line = ft_create_line(reserved);
	reserved = ft_next_line(reserved);
	return (one_line);
}

int main(int argc, char ** argv)
{
	char *the_line;
	// char *the_line2;
	// char *the_line3;
	// char *the_line4;
	// char *the_line5;
	// char *the_line6;
	// char *the_line7;
	// char *the_line8;
	int fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	the_line = ft_gnl(fd);
	// the_line2 = ft_gnl(fd);
	// the_line3 = ft_gnl(fd);
	// the_line4 = ft_gnl(fd);
	// the_line5 = ft_gnl(fd);
	// the_line6 = ft_gnl(fd);
	// the_line7 = ft_gnl(fd);
	// the_line8 = ft_gnl(fd);
	printf("%s", the_line);
	// printf("%s", the_line2);
	// printf("%s", the_line3);
	// printf("%s", the_line4);
	// printf("%s", the_line5);
	// printf("%s", the_line6);
	// printf("%s", the_line7);
	// printf("%s", the_line8);

	// close(fd);
	return (0);
}
