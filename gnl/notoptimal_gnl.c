#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

char *notoptimal_get_next_line(int fd)
{
	char buf;
	int i;

	char *arr = malloc(2);
	arr[0] = '\n';
	arr[1] = '\0';
	i = 3;
	if (read(fd, &buf, 1) == 0)
	{
		free(arr);
		return (0);
	}
	while (buf != '\n' && buf != '\0')
	{
		arr = ft_realloc(arr, i);
		arr[i - 3] = buf;
		arr[i - 2] = '\n';
		arr[i - 1] = '\0';
		i++;
		if (read(fd, &buf, 1) == 0)
			return (arr);
	}
	return (arr);
}

int main(int argc, char ** argv)
{
    char *the_line;
	int fd;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
    the_line = notoptimal_get_next_line(fd);
    printf("%s", the_line);

	close(fd);
    return (0);
}
