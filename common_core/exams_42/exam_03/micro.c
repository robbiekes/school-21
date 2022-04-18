#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_data
{
	int w;
	int h;
	char back;
	FILE *file;
	char *field;
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

int read_data(t_data *data)
{
	int count;
	if ((count = fscanf(data->file, "%d %d %c\n", &data->w, &data->h, &data->back)) != 3)
		return (1);
	if (data->w <= 0 || data->w > 300 || data->h <= 0 || data->h > 300)
		return (1);
	return (0);
}

// if (i >= rect->x && i <= (rect->x + rect->w) && j >= )
// {
// 	if (rect->tyep == 'R')
// 		return (1);
// 	if (x - rect->x < 1) || rect->x + rect->w - x < 1 || 
// }

int formula(t_rect *rect, int x, int y)
{
	if (x >= rect->x && x <= (rect->x + rect->width) && (y >= rect->y && y <= (rect->y + rect->height)))
	{
		if (rect->type == 'R')
			return (1);
		if (((x - rect->x < 1) || (rect->x + rect->width) - x < 1) || ((y - rect->y < 1) || ((rect->y + rect->height) - y < 1)))
			return (1);
	}
	return (0);
}

void	draw_rect(t_data *data, t_rect *rect)
{
	int i = 0, j = 0;
	while (i < data->w)
	{
		j = 0;
		while (j < data->h)
		{
			if (formula(rect, i, j))
				data->field[j * data->w + i] = rect->c;
			j++;
		}
		i++;
	}
}

int func(t_data *data)
{
	t_rect *rect = (t_rect *)malloc(sizeof(t_rect));
	int count;
	while ((count = fscanf(data->file, "%c %f %f %f %f %c\n", &rect->type, &rect->x, &rect->y, &rect->width, &rect->height, &rect->c)) == 6)
	{
		if (rect->width <= 0 || rect->height <= 0 || (rect->type != 'R' && rect->type != 'r'))
		{
			free(rect);
			return (1);
		}
		draw_rect(data, rect);
	}
	free(rect); // leak
	if (count != -1)
		return (1);
	return (0);
}

void print_field(t_data *data)
{
	int i = 0, j = 0; // unused variable
	while (i < data->h)
	{
		write(1, &(data->field[i * data->w]), data->w);
		write(1, "\n", 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	t_data *data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (!(data->file = fopen(av[1], "r")))
	{
		free(data); // leak
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (read_data(data))
	{
		free(data); // leak
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	data->field = (char *)malloc(sizeof(char) * (data->w * data->h));
	memset(data->field, data->back, (data->w * data->h));
	if (func(data))
	{
		free(data->field); // leak
		free(data); // leak
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	print_field(data);
	fclose(data->file);
	free(data->field);
	free(data);
	return (0);
}
