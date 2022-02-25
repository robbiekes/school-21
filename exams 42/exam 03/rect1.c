#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
	int width;
	int height;
	char background;
	FILE *file;

	char **field;
} t_data;

typedef struct s_rect
{
	char type;
	float x;
	float y;
	float width;
	float height;
	char c; 
} t_rect;

int	check_args(t_data *data)
{
	if (data->width > 0 && data->width <= 300 && data->height > 0 && data->height <= 300)
		return (0);
	return (1);
}

int field_data(t_data *data)
{
	int count = 0;
	count = fscanf(data->file, "%d %d %c\n", &data->width, &data->height, &data->background);
	if (count != 3)
		return (1);
	if (check_args(data))
		return (1);
	return (0);
}

void make_field(t_data *data)
{
	int i = -1;
	data->field = (char **)malloc(sizeof(char *) * data->height);
	while (++i < data->height)
	{
		data->field[i] = (char *)malloc(sizeof(char) * data->width);
		memset(data->field[i], data->background, data->width);
	}
}

int check_rect_args(t_rect *rect)
{
	if ((rect->type != 'r' && rect->type != 'R') || rect->width <= 0 || rect->height <= 0)
		return (1);
	return (0);
}

void fill_matrix(t_data *data)
{
	int i = 0;
}

int	rect_data(t_data *data)
{
	t_rect *rect = (t_rect *)malloc(sizeof(t_rect));
	int count = 0;
	while (count = fscanf(data->file, "%c %f %f %f %f %c\n", &rect->type, &rect->x, &rect->y, 
			&rect->width, &rect->height, &rect->c) == 6)
	{
		if (check_rect_args(rect))
			return (1);
		fill_matrix(data);
	}
	if (count != -1)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int res = 0;
	t_data *data = (t_data *)malloc(sizeof(t_data));

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(data->file = fopen(av[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (res == field_data(data))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	make_field(data);
	if (res == rect_args(data))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}

}