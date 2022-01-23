/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:38:12 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/23 15:42:33 by mgwyness         ###   ########.fr       */
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

void	free_arrays(t_map *map_data, int **arr)
{
	int	i;

	i = 0;
	while (i < map_data->height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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

	x_step = p1->x - p->x;
	y_step = p1->y - p->y;
	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p->x - p1->x) || (int)(p->y - p1->y))
	{
		if (p->x >= 0 && p->x < HEIGHT && p->y >= 0 && p->y < WIDTH)
			my_mlx_pixel_put(data, (int)p->x, (int)p->y, colour);
		p->x += x_step;
		p->y += y_step;
	}
}
////////////count height of the map/////////////////
int	get_height(char *file)
{
	int		strings;
	char	*line;
	int		fd;
	char *tmp;

	strings = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = 0;
		strings++;
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (strings);
}
////////free splitted string and terminate the whole program/////////
void	free_splitted_exit(char **arr, int flag)
{
	int	i;

	i = 0;
	while (arr[i])
	{
			free(arr[i]);
			i++;
	}
	free(arr[i]);
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
	while (string)
	{
		string = get_next_line(fd);
		if (string)
			free(string);
	}
	close(fd);
	return (ft_ptrlen(splitted_str));
}

void	fill_colours(t_map *map_data, char **str, int i)
{
	int	j;
	char **substr;

	j = 0;
	while (j < map_data->width)
	{
		substr = ft_split(str[j], ',');
		if (substr[1] != 0)
			map_data->colours[i][j] = ft_atoi_base(&(substr[1][2]), "0123456789ABCDEF");
		else
			map_data->colours[i][j] = 0xff0000;
		j++;
		free_splitted_exit(substr, 0);
	}
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
		fill_colours(map_data, splitted_str, i);
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
	close(fd);
}

////////////////read a map/////////////////
void	read_map(char *map, t_map *map_data)
{
	int	i;
	
	i = 0;
	if (!get_height(map) || !get_width(map))
	{
		free(map_data);
		exit(0);
	}
	map_data->height = get_height(map);
	 map_data->width = get_width(map);
	map_data->z_matrix = (int **)malloc(sizeof(int *) * map_data->height);
	map_data->colours = (int **)malloc(sizeof(int *) * map_data->height);
	if (!(map_data->z_matrix))
		exit(0);
	while (i < map_data->height)
	{
		map_data->z_matrix[i] = (int *)malloc(sizeof(int) * map_data->width); // check malloc
		map_data->colours[i] = (int *)malloc(sizeof(int) * map_data->width);
		i++;
	}
	fill_matrix(map_data, map);
}

void	shift_dot(t_point *p, t_map *map_data)
{
	p->x += map_data->shift_x;
	p->y += map_data->shift_y;
}

void	view_above(t_map *map_data, t_data *data)
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
			if (x < map_data->width - 1)
			{
				p1.x = (x + 1) * map_data->zoom;
				p1.y = y * map_data->zoom;
				map_data->colour = map_data->colours[y][x];
				shift_dot(&p, map_data);
				shift_dot(&p1, map_data);
				draw_line(&p, &p1, data, map_data->colour);
			}
			if (y < map_data->height - 1)
			{
				p.x = x * map_data->zoom;
				p.y = y * map_data->zoom;
				p1.x = x * map_data->zoom;
				p1.y = (y + 1) * map_data->zoom;
				map_data->colour = map_data->colours[y][x];
				shift_dot(&p, map_data);
				shift_dot(&p1, map_data);
				draw_line(&p, &p1, data, map_data->colour);
			}
			x++;
		}
		y++;
	}
}

void	isometric_map(t_map *map_data, t_data *data)
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
			if (x < map_data->width - 1)
			{
				p1.x = (x + 1) * map_data->zoom;
				p1.y = y * map_data->zoom;
				map_data->colour = map_data->colours[y][x];
				isometry(&p, (map_data->z_matrix[y][x] * map_data->zoom / 2));
				isometry(&p1, (map_data->z_matrix[y][x + 1] * map_data->zoom / 2));
				shift_dot(&p, map_data);
				shift_dot(&p1, map_data);
				draw_line(&p, &p1, data, map_data->colour);
			}
			if (y < map_data->height - 1)
			{
				p.x = x * map_data->zoom;
				p.y = y * map_data->zoom;
				p1.x = x * map_data->zoom;
				p1.y = (y + 1) * map_data->zoom;
				map_data->colour = map_data->colours[y][x];
				isometry(&p, (map_data->z_matrix[y][x] * map_data->zoom / 2));
				isometry(&p1, (map_data->z_matrix[y + 1][x] * map_data->zoom / 2));
				shift_dot(&p, map_data);
				shift_dot(&p1, map_data);
				draw_line(&p, &p1, data, map_data->colour);
			}
			x++;
		}
		y++;
	}
}

void	background(t_map *map_data)
{
	int	y;
	int	x;
	
	y = 0;
	x = 0;
	while (y < HEIGHT)
	{	
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(map_data->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	update_img(t_map *map_data, int key)
{
	static int view_mode = 0;

	background(map_data);
	if (key == 19)
		view_mode = 1;
	if (key == 20)
		view_mode = 0;
	if (view_mode)
		view_above(map_data, map_data->img);
	else
		isometric_map(map_data, map_data->img);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, map_data->img->image, 0, 0);
}

int	key_num(int	key, t_map *map_data)
{
	static int	above;

	above = 0;
	printf("%d\n", key);
	if (key == 124)
		map_data->shift_x += 5;
	else if (key == 123)
		map_data->shift_x -= 5;
	else if (key == 126)
		map_data->shift_y -= 5;
	else if (key == 125)
		map_data->shift_y += 5;
	else if (key == 53)
	{
		mlx_destroy_image(map_data->mlx_ptr, map_data->win_ptr);
		mlx_clear_window(map_data->mlx_ptr, map_data->win_ptr);
		free_arrays(map_data, map_data->z_matrix);
		free_arrays(map_data, map_data->colours);
		free(map_data);
		exit (0);
	}
	else if (key == 13)
		map_data->zoom += map_data->zoom / 25;
	else if (key == 1)
		map_data->zoom -= map_data->zoom / 25;
	else if (key == 19)
		view_above(map_data, map_data->img);
	else if (key == 20)
		isometric_map(map_data, map_data->img);
	else
		return (0);
	update_img(map_data, key);
	return (0);
}

int	mouse_zoom(int key, int x, int y, t_map *map_data)
{
	float	zoom;
	
	printf("%d\n", key);
	zoom = map_data->zoom;
	if (key == MOUSE_UP && zoom < 100)
		map_data->zoom += zoom / 16;
	else if (key == MOUSE_DOWN && zoom > 1.1)
		map_data->zoom -= zoom / 16;
	else if (key == 19)
		view_above(map_data, map_data->img);
	else
		isometric_map(map_data, map_data->img);
	update_img(map_data, key);
	return (x + y);
}


int main(int argc, char **argv)
{
	t_data	img;
	t_map	*map_data;

	map_data = (t_map *)malloc(sizeof(t_map));
	read_map(argv[1], map_data);
	map_data->mlx_ptr = mlx_init();
	map_data->win_ptr = mlx_new_window(map_data->mlx_ptr, HEIGHT, WIDTH, "FDF");
	img.image = mlx_new_image(map_data->mlx_ptr, HEIGHT, WIDTH);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel,
					&img.line_len, &img.endian);
	map_data->zoom = 20;
	map_data->img = &img;
	map_data->shift_x = 300;
	map_data->shift_y = 200;
	isometric_map(map_data, map_data->img);
	mlx_hook(map_data->win_ptr, 4, 0, mouse_zoom, map_data);
	mlx_key_hook(map_data->win_ptr, key_num, map_data);
	mlx_put_image_to_window(map_data->mlx_ptr, map_data->win_ptr, img.image, 0, 0);
	mlx_loop(map_data->mlx_ptr);
		free_arrays(map_data, map_data->z_matrix);
		free_arrays(map_data, map_data->colours);
		free(map_data);
} 
