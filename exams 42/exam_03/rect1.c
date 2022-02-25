#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

typedef struct s_circ
{
	char type;
	float x;
	float y;
	float r;
	char c; 
} t_circ;

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

int check_rect_args(t_circ *circ)
{
	if ((circ->type != 'c' && circ->type != 'C') || circ->r <= 0)
		return (1);
	return (0);
}

int is_part_of_rect(t_circ *circ, int x_point, int y_point)
{
	float dist = sqrtf((circ->x - x_point) * (circ->x - x_point) + (circ->y - y_point) * (circ->y - y_point));

	if (dist <= circ->r)
	{
		if (circ->type == 'C')
			return (1);
		if (circ->r - dist < 1)
			return (1);
	}
	return (0);
}

void fill_matrix(t_data *data, t_circ *rect)
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
	t_circ *rect = (t_circ *)malloc(sizeof(t_circ));
	int count = 0;
	while ((count = fscanf(data->file, "%c %f %f %f %c\n", &rect->type, &rect->x, &rect->y, 
			&rect->r, &rect->c)) == 5)
	{
		if (check_rect_args(rect))
			return (1);
		fill_matrix(data, rect);
	}
	if (count != -1)
		return (1);
	return (0);
}

void print_field(t_data *data)
{
	int i = 0, j = 0;
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
	int res = 0;
	t_data *data = (t_data *)malloc(sizeof(t_data));

	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(data->file = fopen(av[1], "r")))
	{
		write(1, "Error: Operation file corrupted 134\n", 36);
		return (1);
	}
	if ((res = field_data(data)))
	{
		write(1, "Error: Operation file corrupted 139\n", 36);
		return (1);
	}
	make_field(data);
	if ((res = rect_args(data)))
	{
		write(1, "Error: Operation file corrupted 145\n", 36);
		return (1);
	}
	print_field(data);
	fclose(data->file);
	return (0);
}