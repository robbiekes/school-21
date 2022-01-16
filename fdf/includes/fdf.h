#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_map
{
	int		height;
	int		width;
} 			t_map;

typedef struct s_data
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_data;

///////utils//////////
int			ft_atoi(char *str);
char		**ft_split(char *s, char c);
int			ft_ptrlen(char **s);

////////in use////////
void		finish(int exitcode);
void	read_map(char *map, t_map *map_data);
int	get_height(char *file);
int	get_width(char *file);
void	free_splitted_exit(char **arr);
char	*get_next_line(int fd);



#endif