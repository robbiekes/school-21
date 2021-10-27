#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_string
{
	char *array;
	int size;
	int memory;
} t_string;

char	*notoptimal_get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_next_line(char *reserved);
char	*ft_strchr(const char *s, int c);

# ifndef BUFFER_SIZE
#  define	BUFFER_SIZE 15
# endif

#endif