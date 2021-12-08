#include "ft_printf.h"
#include <stdio.h>
// 1.1d
// 1.1s
// 1.1x

static int	ft_numlen(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_putnbr(int n)
{
	long long	temp;
	long long	tmp_n;

	tmp_n = (long long)n;
	if (tmp_n < 0)
	{
		tmp_n = -tmp_n;
		write(1, "-", 1);
	}
	if (tmp_n >= 10)
		ft_putnbr(tmp_n / 10);
	temp = (tmp_n % 10) + '0';
	write(1, &temp, 1);
	return (ft_numlen(n));
}

int my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_putstr(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
		write(1, &str[i++], 1);
	return (i);
}

int my_atoi(const char *a)
{
	int			i;
	long int	res;
	int			sign;

	i = 0;
	sign = 1;
	res = 0;
	while (a[i] == ' ' && (a[i] >= 9 && a[i] <= 13))
		i++;
	if (a[i] == '-')
		sign = -1;
	if (a[i] == '-' || a[i] == '+')
		i++;
	while (a[i] >= '0' && a[i] <= '9')
	{
		res = (res * 10) + (a[i] - '0');
		i++;
	}
	return (res * sign);
}

int print_s(char *str, t_args *args)
{
	int count;

	count = 0;
	if (!str)
	{
		if (args->precision >= 0 || args->precision > 6)
			args->precision = 6;
		while (count < (args->width - args->precision))
			count += write(1, " ", 1);
		count += write(1, "(null)", args->precision);
		return (count);
	}
	if (args->width >= args->precision && args->width >= my_strlen(str))
	{
		if (args->precision >= my_strlen(str) || args->precision == 0)
			args->precision = my_strlen(str);
		while (count < (args->width - args->precision))
			count += write(1, " ", 1);
	}
		while (count < (args->width - my_strlen(str)))
			count += write(1, " ", 1);
	if (args->precision <= my_strlen(str) && args->precision != 0)
		count += ft_putstr(str, args->precision);
	else if (args->precision != 0 || args->width > 0)
		count += ft_putstr(str, my_strlen(str));
	return (count);
}

int print_d(int num, t_args *args)
{
	int	count;
	int skip;

	count = 0;
	if (args->precision == 0 && args->width == 0 && num == 0)
		skip = 1;
	if (args->precision <= ft_numlen(num))
		args->precision = 0;
	if (args->width > args->precision)
	{
		while (count < (args->width - (ft_numlen(num) - args->precision)))
			count += write(1, " ", 1);
	}
	count = 0;
	if (args->precision > ft_numlen(num))
	{
		while (count < (args->precision - ft_numlen(num)))
			count += write(1, "0", 1);
		count += ft_putnbr(num);
	}
	else if (!skip)
		count += ft_putnbr(num);
	return (count);
}

int print_argument(va_list *argptr, t_args *args)
{
	if (args->conversion == 'd' || args->conversion == 'i')
		return (print_d(va_arg(*argptr, int), args));
	else if (args->conversion == 's')
		return (print_s(va_arg(*argptr, void *), args));
	// else if (args->conversion == 'x')
	// 	return (print_x_low(argptr, args, 1));
	// else if (args->conversion == 'X')
	// 	return (print_x_high(argptr, args, 0));
}

int handle_argument(const char *string, t_args *args)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	args->width = 0;
	i = 0;
	if (string[i] >= '0' && string[i] <= '9')
	{
		args->width = my_atoi(&string[i]);
		while (string[i] >= '0' && string[i] <= '9')
			i++;
	}
	if (string[i] != '.')
		args->precision = 0;
	else if (string[i] == '.' && string[i + 1] >= '0' && string[i + 1] <= '9')
	{
		i++;
		args->precision = my_atoi(&string[i]);
		while (string[i] >= '0' && string[i] <= '9')
			i++;
	}
	args->conversion = string[i];
	i++;
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list	argptr;
	va_start(argptr, format);
	int	i;
	int	count;
	t_args	args; // аргумент ака 1.1s

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i += handle_argument(&format[i + 1], &args);
			count += print_argument(&argptr, &args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(argptr);
	return (count);
}

int main(void)
{
	int orig = 0;
	int ft = 0;
	orig = printf("orig = %0s %0s %0s %0s %0s\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	ft = ft_printf("ft   = %0s %0s %0s %0s %0s\n", "", "toto", "0123456789", "tjehurthteutuiehteute", NULL);
	printf("orig len = %d\n", orig);
	printf("ft len = %d\n", ft);
}

