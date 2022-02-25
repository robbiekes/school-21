#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
	int		width;
	int		height;
	char 	background;
	FILE 	*file;

	char 	**field;
}			t_data;

typedef struct s_rect
{
	char 	type;
	float 	width;
	float 	height;
	float 	x;
	float 	y;
	char 	c;


}			t_rect;

int	error_args(void)
{
	write(1, "Error: argument\n", 16);
	return (1);
}

int	error_file(void)
{
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

int	check_args(t_data *data)
{
	if (data->width > 0 && data->width <= 300 && data->height > 0 && data->height <= 300)
		return (0);
	return (1);
}

int	field_args(t_data *data)
{
	int count = 0;
	count = fscanf(data->file, "%d %d %c\n", &data->width, &data->height, &data->background);
	if (count != 3)
		return (1);
	if (check_args(data))
		return (1);
	return (0);
}

void	init_field(t_data *data)
{
	int	i = 0;
	data->field = (char **)malloc(sizeof(char *) * data->height);
	while (i < data->height)
	{
		data->field[i] = (char *)malloc(sizeof(char) * data->width);
		memset(data->field[i], data->background, data->width);
		i++;
	}
}

int	check_rect_args(t_rect *rect)
{
	if ((rect->type != 'r' && rect->type != 'R') || (rect->width <= 0 || rect->height <= 0))
		return (1);
	return (0);
}

int	is_part_of_rect(t_rect *rect, int x_point, int y_point)
{
	if (x_point >= rect->x && x_point <= rect->x + rect->width && y_point >= rect->y && y_point <= rect->y + rect->height)
	{
		if (rect->type == 'R')
			return (1);
		if (x_point - rect->x < 1 || y_point - rect->y < 1 || (rect->x + rect->width) - x_point < 1 || (rect->y + rect->height) - y_point < 1)
			return (1);
	}
	return (0);
}

void	fill_matrix(t_data *data, t_rect *rect)
{
	int i = 0, j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (is_part_of_rect(rect, i, j))
				data->field[j][i] = rect->c;
			i++;
		}
		j++;
	}
}

int	rect_args(t_data *data)
{
	int count;
	t_rect *rect = (t_rect *)malloc(sizeof(t_rect));

	while ((count = fscanf(data->file, "%c %f %f %f %f %c\n", &rect->type, &rect->x,
			&rect->y, &rect->width, &rect->height, &rect->c) == 6))
	{
		if (check_rect_args(rect))
			return (1);
		fill_matrix(data, rect);
	}
	return (0);
}

void	print_rect(t_data *data)
{
	int	i = 0, j = 0;

	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			write(1, &data->field[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int main(int ac, char **av)
{
	t_data *data = (t_data *)malloc(sizeof(t_data));
	if (ac != 2)
		return (error_args());
	data->file = fopen(av[1], "r");
	if (!(data->file))
		return (error_file());
	if (field_args(data))
		return(error_args());
	init_field(data);
	rect_args(data);
	print_rect(data);
	return (0);
}