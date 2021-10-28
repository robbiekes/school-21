#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "get_next_line.h"

int main(int argc, char **argv)
{
	char *the_line;
	char *the_line2;
	char *the_line3;
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
	the_line2 = ft_gnl(fd);
	the_line3 = ft_gnl(fd);
	printf("%s", the_line);
	printf("%s", the_line2);
	printf("%s", the_line3);
	return (0);
}