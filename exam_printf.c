#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

static int ft_nbrlen(long num, int base_len)
{
	int i = 1;
	while (num >= base_len)
	{
		num /= base_len;
		i++;
	}
	return (i);
}

static void ft_putnbr(long n, int base_len, char *base)
{
	if (n >= base_len)
		ft_putnbr(n / base_len, base_len, base);
	write(1, &base[n % base_len], 1);
}

int ft_printf(const char *format, ...)
{
	int i = 0;
	va_list ap;
	char *s;
	long nbr;
	int width;
	int prec;
	int spaces;
	int neg;
	int len;
	int zeros;
	int length;
	va_start(ap, format);
	length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			width = 0;
			prec = -1;
			neg = 0;
			len = 0;
			zeros = 0;
			spaces = 0;
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
				s = va_arg(ap, char *);
				if(!s)
					s = ("(null)");
				while (s[len])
					len++;
			}
			if (format[i] == 'd')
			{
				nbr = va_arg(ap, int);
				if (nbr < 0)
				{
					nbr = -nbr;
					neg = 1;
				}
				len = ft_nbrlen(nbr, 10) + neg;
			}
			if (format[i] == 'x')
			{
				nbr = va_arg(ap, unsigned);
				len = ft_nbrlen(nbr, 16);
			}
		if (prec >= len && format[i] != 's')
			zeros = prec - len + neg;
		else if (prec > -1 && prec < len && format[i] == 's')
			len = prec;
		else if (prec == 0 && (format[i] == 's' || nbr == 0))
			len = 0;
		spaces = width - zeros - len;
		while (spaces-- > 0)
			write(1, " ", 1);
		if (neg)
			write (1, "-", 1);
		while (zeros-- > 0)
			length += write(1, "0", 1);
		if (format[i] == 's')
			length += write(1, s, len);
		else if (format[i] == 'd')
			ft_putnbr(nbr, 10, "0123456789");
		else if (format[i] == 'x')
			ft_putnbr(nbr, 16, "0123456789abcdef");
		length += len;
	}
	else
		length += write(1, &format[i], 1);
	i++;
	}
	va_end(ap);
	return (length);
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