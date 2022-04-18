#include <stdio.h>
#include <math.h>
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

typedef struct s_circ
{
	char type;
	float x;
	float y;
	float r;
	char c;
} t_circ;

int read_data(t_data *data)
{
	int count = 0;
	count = fscanf(data->file, "%d %d %c\n", &data->w, &data->h, &data->back);
	if (count != 3)
		return (1);
	if (data->w <= 0 || data->w > 300 || data->h <= 0 || data->h > 300 )
		return (1);
	return (0);
}

int formula(t_circ *circ, int x_point, int y_point)
{
	float dist = sqrtf((y_point - circ->y) * (y_point - circ->y) + (x_point - circ->x) * (x_point - circ->x));

	if (dist <= circ->r)
	{
		if (circ->type == 'C')
			return (1);
		if (circ->r - dist < 1)
			return (1);
	}
	return (0);
}

void draw_circ(t_data *data, t_circ *circ)
{
	int i = 0, j = 0;
	while (i < data->w)
	{
		j = 0;
		while (j < data->h)
		{
			if (formula(circ, i, j))
				data->field[j * data->w + i] = circ->c;
			j++;
		}
		i++;
	}
}

int func(t_data *data)
{
	t_circ *circ = (t_circ *)malloc(sizeof(t_circ));
	int count = 0;
	while ((count = fscanf(data->file, "%c %f %f %f %c\n", &circ->type, &circ->x, &circ->y, &circ->r, &circ->c) == 5))
	{
		if ((circ->type != 'C' && circ->type != 'c') || circ->r <= 0)
		{
			free(circ);
			return (1);
		}
		draw_circ(data, circ);
	}
	free(circ);
	if (count != -1)
		return (1);
	return (0);
}

void print_field(t_data *data)
{
	int i = 0, j = 0;
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
	data->file = fopen(av[1], "r");
	if (!data->file)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (read_data(data))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	data->field = (char *)malloc(sizeof(char) * (data->w * data->h));
	memset(data->field, data->back, (data->w * data->h));
	if (!func(data))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	print_field(data);

	fclose(data->file);
	free(data->field);
	free(data);
	return (0);
}