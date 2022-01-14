#ifndef FDF_H
#define FDF_H

#include <mlx.h>

typedef struct s_data
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_data;

#endif