#include "micro_paint.h"

int	check_args(t_field *field)
{
	return (field->width > 0 && field->width <= 300 && field->height > 0 && field->height <= 300);
}

int	read_args(FILE *file, t_field *field)
{
	int	symbols = 0;

	if ((symbols = fscanf(file, "%d %d %c\n", &field->width, &field->height, &field->background)) != 3)
		return (0);
	if (!check_args(field))
		return (0);
	return (1);
}



void	rect_shape(t_field *field)
{
	int	symbols = 0;
	char 

	if ((symbols = fscanf(file, "%c %d %d %d %c\n", &rect->rect_type &rect->width, &rect->height, &rect->background)) != 5)
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

int main(int ac, char **av)
{
	int	error_code = 0;
	FILE	*file;
	t_field *field = (t_field *)malloc(sizeof(t_field));
	t_rect	*rect = (t_rect *)malloc(sizeof(t_rect));
	rect->shape
	field->width = 0;
	field->height = 0;
	field->background = 0;

	if (ac != 2)
		return (error_args());
	if (!(file = fopen(av[1], "r")))
		return (error_file());
	if (!(read_args(file, field)))
		error_args();
	rect_shape(rect);
	// error_code = draw_rect(/*filepath*/);
	fclose(file);
	return (error_code);
}
