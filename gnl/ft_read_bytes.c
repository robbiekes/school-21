#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*arr;
	int		i;
	char	*dup;
	int		len;

	arr = (char *)s1;
	len = ft_strlen(arr);
	i = 0;
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	while (arr[i])
	{
		dup[i] = arr[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (0);
}

static char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	int		len_d;

	i = 0;
	len_d = ft_strlen(dst);
	while (i < n && src[i] != '\0')
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, int count)
{
	char	*arr;
	int		len_s1;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * (len_s1 + count) + 1);
	if (arr == 0)
		return (0);
	arr[0] = 0;
	ft_strncat(arr, s1, -1);
	ft_strncat(arr, s2, count);
	free(s1);
	return (arr);
}

void ft_cut_str(char *reserved)
{
	int i = 0;
	int j = 0;

	while (reserved[i] != '\n')
		i++;
	i++;
	while (reserved[i] != '\0')
	{
		reserved[j] = reserved[i];
		j++;
		i++;
	}
	reserved[j] = '\0';
}

char *ft_make_line(char *reserved)
{
	int i = 0;
	int len = 0;
	char *str;
	while (reserved[len] != '\n' && reserved[len] != '\0')
		len++;
	if (reserved[len] == '\n')
		str = (char *)malloc(sizeof(char) * (len + 2));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	while (reserved[i] != '\n' && reserved[i] != '\0')
	{
		str[i] = reserved[i];
		i++;
	}
	if (reserved[i] == '\0')
		str[i] = '\0';
	else
	{
		str[i] = '\n';
		str[i + 1] = '\0';
		ft_cut_str(reserved);
	}
	return (str);
}

char *ft_read_bytes(int fd, char *reserved)
{
	int		count;
	char	*buf;
	int		i;

	count = 0;
	i = 0;
	if (reserved == 0)
	{
		reserved = (char *)malloc(sizeof(char));
		reserved[0] = '\0';
	}
	buf = (char *)malloc(sizeof(char) * (42 + 1));
	if (buf == 0)
		return (0);
	while (!ft_strchr(reserved, '\n'))
	{
		count = read(fd, buf, 42);
		if (count <= 0)
		{
			free(buf);
			// printf("(154) count -> %d resered -> (%s)\n", count, reserved);
			if (count == 0 && reserved[0] != '\0')
				return (reserved);	
			return (0);
		}
		reserved = ft_strjoin(reserved, buf, count);
	}
	free(buf);
	return (reserved);
}


char *ft_gnl(fd)
{
	static char *reserved = 0;
	char *arr;

	arr = malloc(sizeof(char) * 42);
	reserved = ft_read_bytes(fd, reserved);
	if (reserved == 0)
		return (0);
	arr = ft_make_line(reserved);
	return (arr);
}

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