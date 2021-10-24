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
	printf("%d %d\n", the_line->size, the_line->memory);
	if (the_line->size == the_line->memory)
	{
		the_line->array = ft_realloc(the_line->array, the_line->size * 2);
		the_line->memory *= 2;
	}
	(the_line->array)[the_line->size] = '\0';
}

// пишу функцию, которая читает по 1 символу из файла/ввода, записывает по 1 символу в массив и возвращает этот массив.
// для массива нужно выделить память, и я выделяю 10 ячеек памяти изначально, потом заполнив их снова выделяю 10 ячеек/
// в структуре есть три поля: массив его длина и выделенная память/
// заполняю массив по 1 символу и увеличиваю размер/ если размер равен количеству выделенной памяти снова выделяю 10 ячеек/

char *notoptimal_get_next_line(int fd)
{
	char buf;
	int i;
	char *res;
	int count;

	t_string *the_line;
	the_line = (t_string *)malloc(sizeof(t_string)); // if malloc == 0
	the_line->array = (char *)malloc(10); // if malloc == 0
	the_line->array[0] = '\0';
	the_line->size = 1;
	the_line->memory = 10;

	if (read(fd, &buf, 1) == 0)
	{
		free(the_line->array);
		free(the_line);
		return (0);
	}
	while (1)
	{
		if (buf == '\n')
			break ;
		ft_push_char(the_line, buf);
		if (read(fd, &buf, 1) == 0)
			break ;
	}
	(the_line->array)[the_line->size - 1] = '\0';
	res = ft_strdup(the_line->array);
	free(the_line->array);
	free(the_line);
	return (res);
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

	// close(fd);
    return (0);
}
