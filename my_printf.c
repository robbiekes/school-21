#include <unistd.h>
#include <stdarg.h>

static int ft_nbrlen(long num, int base_num)
{
	int i = 1;
	while (num >= base_num)
	{
		num /= base_num;
		i++;
	}
	return (i);
}

static int ft_putnbr(long num, int base_num, char *base)
{
	int count = 1;
	if (num >= base_num)
		ft_putnbr(num / base_num, base_num, base);
	count += write(1, &base[num % base_num], 1);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	char *str;
	long nbr;
	int any_len;
	int width;
	int prec;
	int neg;
	int zeros;
	int spaces;
	va_start(ap, format);
	int i = 0;
	int count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			width = 0;
			prec = -1;
			neg = 0;
			zeros = 0;
			spaces = 0;
			any_len = 0;
			while (format[i] >= '0' && format[i] <= '9')
			{
				width = width * 10 + (format[i] - '0');
				i++;
			}
			if (format[i] == '.')
			{
				i++;
				prec = 0;
				while(format[i] >= '0' && format[i] <= '9')
				{
					prec = prec * 10 + (format[i] - '0');
					i++;
				}
			}
			if (format[i] == 's')
			{
				str = va_arg(ap, void *);
				if (str == 0)
					str = "(null)";
				while (str[any_len])
					any_len++;
			}
			if (format[i] == 'd')
			{
				nbr = va_arg(ap, int);
				if (nbr < 0)
				{
					nbr = -nbr;
					neg = 1;
				}
				any_len = ft_nbrlen(nbr, 10) + neg;
			}
			if (format[i] == 'x')
			{
				nbr = va_arg(ap, unsigned);
				nbr = ft_nbrlen(nbr, 16);
			}
			if (format[i] != 's' && prec >= any_len)
				zeros = prec - any_len + neg;
			else if (format[i] == 's' && prec < any_len && prec > -1)
				any_len = prec;
			else if ((format[i] == 's' || nbr == 0) && prec == 0)
				any_len = 0;
			spaces = width - zeros - any_len;
			//printf("\nspaces -> %d = %d - %d - %d\n", spaces, width, any_len, zeros);
			while (spaces-- > 1)
				write(1, " ", 1);
			if (neg)
				write(1, "-", 1);
			while (zeros-- > 0)
				count += write(1, "0", 1);
			if (format[i] == 's')
				count += write(1, str, any_len);
			if (format[i] == 'd')
				ft_putnbr(nbr, 10, "0123456789");
			if (format[i] == 'x')
				ft_putnbr(nbr, 16, "0123456789abcdef");
			printf("\ncount =>%d any_len =>%d\n", count, any_len);
			count += any_len;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

int main(void)
{
	int orig = 0;
	int ft = 0;
	//orig = printf("%.4s %.4s %.4s\n", "toto", "0123456789", "tjehurthteutuiehteute");
	orig = printf("%.4d %.4d %.4d %.4d %.4d %.4d %.4d %.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);

	ft = ft_printf("%.4d %.4d %.4d %.4d %.4d %.4d %.4d %.4d\n", 0, 42, 1, 4554, 2147483647, (int)2147483648, (int)-2147483648, (int)-2147483649);
	printf("%d %d\n", orig, ft);
}