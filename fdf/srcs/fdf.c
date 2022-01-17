/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:38:12 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/17 20:20:40 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
///////////////put pixel on a screen//////////////////////
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->address + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}

int	key_num(int	key, void *data)
{
	printf("%d\n", key);
	return (0);
}

void	isometry(t_point *p, int z)
{
	p->x = (p->x - p->y) * cos(0.8);
	p->y = (p->x + p->y) * sin(0.8) - z;
}

/////////////////draw a line///////////////////////
void	draw_line(t_point *p, t_point *p1, t_data *data, int colour)
{
	float	x_step;
	float	y_step;
	int		max;
	
	// int	z;
	// int	z1;

	// z = map_data->z_matrix[(int)p1->y][(int)p1->x];
	// z1 = map_data->z_matrix[(int)p2->y][(int)p2->x];
	// x *= map_data->zoom;
	// y *= map_data->zoom;
	// x1 *= map_data->zoom;
	// y1 *= map_data->zoom;

	x_step = p1->x - p->x;
	y_step = p1->y - p->y;

	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p->x - p1->x) || (int)(p->y - p1->y))
	{
		my_mlx_pixel_put(data, (int)p->x, (int)p->y, colour);
		p->x += x_step;
		p->y += y_step;
	}
	//isometry(&x, &y, z);
	//isometry(&x1, &y1, z);

}
////////////count height of the map/////////////////
int	get_height(char *file)
{
	int		strings;
	char	*line;
	int		fd;

	strings = 0;
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		strings++;
		free(line);
		line = get_next_line(fd);
	}
	// close (fd);
	return (strings);
}
////////free splitted string and terminate the whole program/////////
void	free_splitted_exit(char **arr, int flag)
{
	int	i;

	i = 0;
	while (arr[i])
			free(arr[i++]);
	free(arr);
	if (flag)
		finish(0);
}

////////////get width of the map///////////////
int	get_width(char *file)
{
	int		fd;
	char	*string;
	char	**splitted_str;
	
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (0);
	string = get_next_line(fd);
	if (string)
	{
		splitted_str = ft_split(string, ' ');
		if (!splitted_str)
			finish(0);
		free(string);
	}
	return (ft_ptrlen(splitted_str));
}

void	fill_matrix(t_map *map_data, char *file)
{
	int		fd;
	int		i;
	int		j;
	char	*string;
	char	**splitted_str;

	fd = open(file, O_RDONLY, 0);
	i = 0;
	j = 0;
	while (i < map_data->height)
	{
		string = get_next_line(fd);
		splitted_str = ft_split(string, ' ');
		j = 0;
		while (j < map_data->width)
		{
			map_data->z_matrix[i][j] = ft_atoi(splitted_str[j]);
			j++;
		}
		free_splitted_exit(splitted_str, 0);
		free(string);
		i++;
	}
	i = 0;
	// while (i < map_data->height)
	// {
	// 	j = 0;
	// 	while (j < map_data->width)
	// 	{
	// 		printf("%3d", map_data->z_matrix[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
}

////////////////read a map/////////////////
void	read_map(char *map, t_map *map_data)
{
	int	i;
	
	i = 0;
	if (!get_height(map) || !get_width(map))
	{
		free(map_data);
		exit (0);
	}
	map_data->height = get_height(map);
	map_data->width = get_width(map);

	if (!(map_data->z_matrix = (int **)malloc(sizeof(int *) * map_data->height)))
		exit (0);
	while (i < map_data->height)
		map_data->z_matrix[i++] = (int *)malloc(sizeof(int) * map_data->width); // check malloc

	fill_matrix(map_data, map);
	// printf("height = %d width = %d\n", map_data->height, map_data->width);
}

void	shift_dot(t_point *p, t_map *map_data)
{
	p->x += map_data->shift_x;
	p->y += map_data->shift_y;
}

void	draw_map(t_map *map_data, t_data *data)
{
	t_point	p;
	t_point p1;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			p.x = x * map_data->zoom;
			p.y = y * map_data->zoom;
			// p.x = 100;
			// p.y = 100;
			// p1.x = 200;
			// p1.y = 200;
			// draw_line(&p, &p1, data, 0x00FFFFFF);
			// return ;
			if (x < map_data->width - 1)
			{
				p1.x = (x + 1) * map_data->zoom;
				p1.y = y * map_data->zoom;
				isometry(&p, map_data->z_matrix[y][x]);
				isometry(&p1, map_data->z_matrix[y][x + 1]);
				shift_dot(&p, map_data);
				shift_dot(&p1, map_data);
				draw_line(&p, &p1, data, 0x00FFFFFF);
			}
			if (y < map_data->height - 1)
			{
				p.x = x * map_data->zoom;
				p.y = y * map_data->zoom;
				p1.x = x * map_data->zoom;
				p1.y = (y + 1) * map_data->zoom;
				isometry(&p, map_data->z_matrix[y][x]);
				isometry(&p1, map_data->z_matrix[y + 1][x]);
				shift_dot(&p, map_data);
				shift_dot(&p1, map_data);
				draw_line(&p, &p1, data, 0x00FFFFFF);
			}
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int main(int argc, char **argv)
{
	t_data	img;
	t_map	*map_data;

	map_data = (t_map *)malloc(sizeof(t_map));
	read_map(argv[1], map_data);
	map_data->mlx_ptr = mlx_init();
	map_data->win_ptr = mlx_new_window(map_data->mlx_ptr, 1000, 1000, "FDF");
	img.image = mlx_new_image(map_data->mlx_ptr, 1000, 1000);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel,
					&img.line_len, &img.endian);
	map_data->zoom = 20;
	map_data->shift_x = 600;
	map_data->shift_y = 100;
	draw_map(map_data, &img);
	mlx_key_hook(map_data->win_ptr, key_num, 0);
	// draw_circle(300, 300, 140, 0x00FF0000, &img);
	// draw_square(&img, &mlx, &mlx_window);
	// draw_circle(500, 300, 138, 0x000000FF, &img);
	// draw_circle(400, 400, 136, 0x00FF0000, &img);
	// draw_line(50, 50, 200, 150, &img);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, img.image, 0, 0);
	mlx_loop(map_data->mlx_ptr);
} 
