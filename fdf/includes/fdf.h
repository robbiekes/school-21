#ifndef FDF_H
#define FDF_H
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x) < 0 ? (-x) : (x))
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_point
{
	float	x;
	float  	y;
}			t_point;

typedef struct s_map
{
	int		height;
	int		width;
	int		zoom;
	int		**z_matrix;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*win_ptr;
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
void		read_map(char *map, t_map *map_data);
int			get_height(char *file);
int			get_width(char *file);
void		free_splitted_exit(char **arr, int flag);
char		*get_next_line(int fd);



#endif