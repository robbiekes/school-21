#include "ft_printf.h"

int handle_argument(char *string, t_args *args)
{
	int	i;

	i = 0;
	args->width = malloc(sizeof(int) * 1);
	args->width = ft_atoi(string);
	while (string[i] != '.')// откуда начать считывать точность?
		i++;
	args->precision = malloc(sizeof(int) * 1);
	args->precision = string[i];


}

int ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list	argptr;
	t_args	args; // аргумент ака 1.1s
	va_start(argptr, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += handle_argument(&format[i + 1], &args);

			count += print_argument(argptr, &args);
		}
		else
			count += write(1, &format[i++], 1);
	}
}