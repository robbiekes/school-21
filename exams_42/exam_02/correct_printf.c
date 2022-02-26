#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

static int ft_nbrlen(long long num, int base_num)
{
	int i = 1;
	while (num >= base_num)
	{
		num /= base_num;
		i++;
	}
	return (i);
}

static int ft_putnbr(long long num, int base_num, char *base)
{
	int count = 0;
	if (num >= base_num)
		count += ft_putnbr(num / base_num, base_num, base);
	count += write(1, &base[num % base_num], 1);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	char *str;
	long long nbr;
	int length;
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
			length = 0;
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
				while (str[length])
					length++;
			}
			else if (format[i] == 'd')
			{
				nbr = va_arg(ap, int);
				if (nbr < 0)
				{
					nbr = -nbr;
					neg = 1;
				}
				length = ft_nbrlen(nbr, 10) + neg;
			}
			else if (format[i] == 'x')
			{
				nbr = va_arg(ap, unsigned);
				length = ft_nbrlen(nbr, 16);
			}
			if (format[i] != 's' && prec >= length)
				zeros = prec - length + neg;
			else if (format[i] == 's' && prec < length && prec > -1)
				length = prec;
			else if ((format[i] == 's' || nbr == 0) && prec == 0)
				length = 0;
			spaces = width - zeros - length;
			while (spaces-- > 0)
				count += write(1, " ", 1);
			if (neg)
				count += write(1, "-", 1);
			while (zeros-- > 0)
				count += write(1, "0", 1);
			if (format[i] == 's')
				count += write(1, str, length);
			if (format[i] == 'd')
			{
				if (nbr || prec)
					count += ft_putnbr(nbr, 10, "0123456789");
			}
			if (format[i] == 'x')
				count += ft_putnbr(nbr, 16, "0123456789abcdef");
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
	orig = printf("%.4s %.4s %.4s\n", "toto", "0123456789", "tjehurthteutuiehteute");
	ft = ft_printf("%.4s %.4s %.4s\n", "toto", "0123456789", "tjehurthteutuiehteute");
	printf("%d %d\n", orig, ft);
}
