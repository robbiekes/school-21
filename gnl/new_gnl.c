#include "get_next_line.h"

char *ft_read_line(int fd, char *str_left)
{
	int count;

	char *buf;
	int i;

	count = 0;
	i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == 0)
		return (0);
	while (!ft_strchr(str_left, '\n') && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
		{
			free(buf);
			return (0);
		}
		str_left = ft_strjoin(str_left, buf);

	}
}

char *ft_gnl(fd)
{
	static char *str_left;
	if (fd < 0)
		return (0);
	
}