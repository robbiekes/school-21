/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:38:12 by mgwyness          #+#    #+#             */
/*   Updated: 2022/01/16 20:33:43 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
///////////////put pixel on a screen//////////////////////
void	my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->address + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = colour;
}
/////////////////draw a line///////////////////////
void	draw_line(int x, int y, int x1, int y1, t_data *img)
{
	int	deltaX = abs(x1 - x);
	int	deltaY = abs(y1 - y);
	int signX = 0;
	int signY = 0;
	if (x < x1)
		signX = 1;
	else
		signX = -1;
	if (y < y1)
		signY = 1;
	else
		signY = -1;
	int error = deltaX - deltaY;
	my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
	while(x != x1 || y != y1) 
	{
		my_mlx_pixel_put(img, x, y, 0x00FF0000);
		int error2 = error * 2;
		if(error2 > -deltaY) 
		{
			error -= deltaY;
			x += signX;
		}
		if(error2 < deltaX) 
		{
			error += deltaX;
			y += signY;
		}
	}
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
void	free_splitted_exit(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
			free(arr[i++]);
	free(arr);
	finish(0);
}

////////////get width of the map///////////////
int	get_width(char *file)
{
	int		string_len;
	int		fd;
	char	*string;
	char	**splitted_str;
	
	fd = open(file, O_RDONLY, 0);
	string = get_next_line(fd);
	if (string)
	{
		splitted_str = ft_split(string, ' ');
		free(string);
		if (!splitted_str)
			finish(0);
		string_len = ft_ptrlen(splitted_str);
	}
	string = get_next_line(fd);
	while (string)
	{
		splitted_str = ft_split(string, ' ');
		if (!splitted_str)
			finish(0);
		if (ft_ptrlen(splitted_str) != string_len)
		{
			write(1, "error\n", 6);
			free(string);
			finish(0);
			// free_splitted_exit(splitted_str);
		}
		 free(string);
		string = get_next_line(fd);
	}
	// close (fd);
	return (string_len);
}
////////////////read a map/////////////////
void	read_map(char *map, t_map *map_data)
{
	printf("height = %d width = %d\n", get_height(map), get_width(map));
}

int main(int argc, char **argv)
{
	t_data	img;
	t_map	*map_data;
	void	*mlx;
	void	*mlx_window;

	map_data = (t_map *)malloc(sizeof(t_map));
	read_map(argv[1], map_data);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1000, 1000, "FDF");
	img.image = mlx_new_image(mlx, 1000, 1000);
	img.address = mlx_get_data_addr(img.image, &img.bits_per_pixel,
					&img.line_len, &img.endian);
	
	// draw_circle(300, 300, 140, 0x00FF0000, &img);
	// draw_square(&img, &mlx, &mlx_window);
	// draw_circle(500, 300, 138, 0x000000FF, &img);
	// draw_circle(400, 400, 136, 0x00FF0000, &img);
	// draw_line(50, 50, 200, 150, &img);
	// mlx_put_image_to_window(mlx, mlx_window, img.image, 0, 0);
	// mlx_loop(mlx);
} 
