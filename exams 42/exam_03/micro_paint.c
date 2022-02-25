# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_data
{
	int		width;
	int		height;
	char	background;
	FILE 	*file;

	char 	**field;
} 			t_data;

typedef struct s_rect
{
	char	type;
	float	width;
	float	height;
	float	x;
	float	y;
	char	fill;

}			t_rect;

int	check_args(t_data *data)
{
	if (data->width > 0 && data->width <= 300 && data->height > 0 && data->height <= 300)
		return (0);
	return (1);
}

int	check_rect_args(t_rect *rect_data)
{
	if ((rect_data->type != 'r' && rect_data->type != 'R') ||
		rect_data->width <= 0 || rect_data->height <= 0)
		return (1);
	return (0);
}

int	is_part_of_rect(int x_point, int y_point, t_rect *rect)
{
	if (x_point >= rect->x && y_point >= rect->y && x_point <= rect->x + rect->width && y_point <= rect->y + rect->height)
	{
		if (rect->type == 'R')
			return (1);
		if (y_point - rect->y < 1 || x_point - rect->x < 1 || (rect->y + rect->height) - y_point < 1 || (rect->x + rect->width) - x_point < 1)
			return (1);
	}
	return (0);
}

void	fill_matrix(t_data *data, t_rect *rect_data)
{
	int	i = 0, j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (is_part_of_rect(i, j, rect_data))
				data->field[j][i] = rect_data->fill;
			i++;
		}
		j++;
	}	
}

void	init_field(t_data *data) // init field + fill array with background
{
	int	j = -1;
	data->field = (char **)malloc(sizeof(char *) * data->height);
	while (++j < data->height)
	{
		data->field[j] = (char *)malloc(sizeof(char) * data->width);
		memset(data->field[j], data->background, data->width);
	}
}

int	field_args(t_data *data)
{
	int	count = 0; // counts params %

	if ((count = fscanf(data->file, "%d %d %c\n", &data->width, &data->height, &data->background)) != 3)
		return (1);
	if (check_args(data))
		return (1);
	return (0);
}

int	rect_args(t_data *data)
{
	int	count = 0;
	t_rect	*rect_data = (t_rect *)malloc(sizeof(t_rect));

	while ((count = fscanf(data->file, "%c %f %f %f %f %c\n", &rect_data->type, &rect_data->x,
		&rect_data->y, &rect_data->width, &rect_data->height, &rect_data->fill)) == 6)
	{
		if (check_rect_args(rect_data))
			return (1);
		fill_matrix(data, rect_data);
	}
	if (count != -1)
		return (1);
	return (0);
}

int	error_args(void)
{
	write(1, "Error: argument\n", 16);
	return (1);
}

int error_file(void)
{
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

void	print_field(t_data *data)
{
	int	i = 0, j = 0;

	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			write(1, &(data->field[j][i]), 1);
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
	if (!(data->file = fopen(av[1], "r")))
		return (error_file());

	if (field_args(data))
		return (error_file());
	init_field(data);


	rect_args(data);
	
	print_field(data);

	fclose(data->file);
	return (0);
}
