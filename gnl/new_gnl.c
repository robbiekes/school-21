#include "get_next_line.h"

char *ft_read_buf(int fd, char *str_left)
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
	free(buf);
	return (str_left);

char *ft_create_line(char *str_left)
{
	char *one_line;
	
	while(str_left[i] != '\0')
		i++;
	one_line = (char *)malloc(sizeof(char) * (i + 1));
	if (str_left == 0)
		return (0);
	i = 0;
	while (str_left[i])
	{
		str[i] = str_left[i];
		i++;
	}
}

char *ft_gnl(fd)
{
	static char *str_left;
	char *one_line;

	if (fd < 0)
		return (0);
	str_left = ft_read_buf(fd, str_left);
	one_line = ft_create_line(str_left);
	printf("%s\n", str_left);
	return (one_line);
}

int main()
{
	char *arr1;
	arr = ft_gnl(fd);
	printf("%s\n", arr1);
	returnn (0);
}