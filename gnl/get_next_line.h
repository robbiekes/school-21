#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> // remove

typedef struct s_string
{
	char *array;
	int size;
	int memory;
} t_string;

char	*ft_gnl(int fd);
char	*ft_read_bytes(int fd, char *reserved);
char	*ft_create_line(char *reserved);
void	ft_cut_str(char *reserved);

char	*ft_strjoin(char *s1, char *s2, int count);
char	*ft_strncat(char *dst, const char *src, size_t n);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);


# ifndef BUFFER_SIZE
#  define	BUFFER_SIZE 15
# endif

#endif