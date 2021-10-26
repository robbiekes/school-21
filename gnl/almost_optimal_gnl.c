#include <stdio.h>
#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*copy_to;
	char	*copy_from;
	int		i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	copy_from = (char *)src;
	copy_to = (char *)dst;
	while (n > 0)
	{
		copy_to[i] = copy_from[i];
		i++;
		n--;
	}
	return (dst);
}

char *ft_realloc(void *ptr, size_t newsize)
{
	char *newptr;
	char *tmp_ptr;
	int oldsize;

	oldsize = 0;
	tmp_ptr = (char *)ptr;
	newptr = (char *)malloc(sizeof(char) * newsize);
	if (newptr == 0)
		return (0);
	while (tmp_ptr[oldsize] != '\0')
		oldsize++;
	ft_memcpy(newptr, ptr, oldsize);
	free(ptr);
	return (newptr);
}

void ft_push_char(t_string *the_line, char c)
{
	(the_line->array)[the_line->size - 1] = c;
	the_line->size += 1;
	if (the_line->size == the_line->memory)
	{
		the_line->array = ft_realloc(the_line->array, the_line->size * 2);
		the_line->memory *= 2;
	}
	(the_line->array)[the_line->size] = '\0';
}

char *notoptimal_get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	static int i = 0;
	char *res;
	int count;

	t_string *the_line;
	the_line = (t_string *)malloc(sizeof(t_string)); // if malloc == 0
	the_line->array = (char *)malloc(BUFFER_SIZE + 1); // if malloc == 0
	the_line->array[0] = '\0';
	the_line->size = 1;
	the_line->memory = BUFFER_SIZE + 1;
	while (i < BUFFER_SIZE && buf[i] != '\n' && buf[i] != '\0')
	{
		ft_push_char(the_line, buf[i]);
		if (i < BUFFER_SIZE && buf[i] == '\n')
			ft_push_char(the_line, buf[i]);
		i++;
	}
	printf("(74) i = %d\n", i);
	if ((i == 0 || buf[i] != '\0') && (buf[i] != '\n' || i == BUFFER_SIZE))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == 0)
		{
			free(the_line->array);
			free(the_line);
			return (0);
		}
		while (count)
		{
			i = 0;
			printf("(88) i = %d\n", i);
			while (i < count && buf[i] != '\n' && buf[i] != '\0')
			{
				ft_push_char(the_line, buf[i]);
				i++;
			}
			printf("(94) i = %d, count = %d, buf = %s\n", i, count, buf);
			if (i < count && buf[i] == '\n')
			{
				ft_push_char(the_line, buf[i]);
				break ;
			}
			count = read(fd, buf, BUFFER_SIZE);
			printf("count = %d\n", count);
		}
	}
	i++;
	(the_line->array)[the_line->size - 1] = '\0';
	res = ft_strdup(the_line->array);
	free(the_line->array);
	free(the_line);
	return (res);
}

int main(int argc, char ** argv)
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
	the_line = notoptimal_get_next_line(fd);
	the_line2 = notoptimal_get_next_line(fd);
	the_line3 = notoptimal_get_next_line(fd);
	// the_line4 = notoptimal_get_next_line(fd);
	// the_line5 = notoptimal_get_next_line(fd);
	// the_line6 = notoptimal_get_next_line(fd);
	// the_line7 = notoptimal_get_next_line(fd);
	// the_line8 = notoptimal_get_next_line(fd);
	printf("%s", the_line);
	printf("%s", the_line2);
	printf("%s", the_line3);
	// printf("%s", the_line4);
	// printf("%s", the_line5);
	// printf("%s", the_line6);
	// printf("%s", the_line7);
	// printf("%s", the_line8);

	// close(fd);
	return (0);
}
