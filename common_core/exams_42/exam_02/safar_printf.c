#include <stdio.h>
#include <limits.h>
#define S		"salam_%6.3s %15.13d\n", "aleykum", INT_MIN

#include <stdarg.h>
#include <unistd.h>
#define TRUE	1
#define FALSE	0

typedef struct	s_pf
{
	int		count;
	int		width;
	int		prec;
	char	type;
	int		minus;
}				t_pf;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	char *head;

	head = s;
	while (*s)
		s++;
	return (s - head);
}

int		get_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int		get_min(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}

int		ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int		ft_atoi(char *s)
{
	int num;

	num = 0;
	while (ft_isdigit(*s))
		num = num * 10 + *s++ - '0';
	return (num);
}

void	print_num(t_pf *pf, unsigned int num, int base)
{
	char	buf[32];
	char	*pbuf;
	char	*hexdigits = "0123456789abcdef";
	int		numlen;

	pbuf = &buf[31];
	if (num == 0 && pf->prec)
		*pbuf-- = '0';
	else
	{
		while (num)
		{
			*pbuf-- = hexdigits[num % base];
			num /= base;
		}
	}
	numlen = &buf[31] - pbuf;
	pf->prec = pf->prec < 0 ? 1 : pf->prec;
	pf->count += get_max(pf->width, get_max(pf->prec, numlen) + pf->minus);
	pf->width -= pf->minus;
	while (pf->width > numlen && pf->width-- > pf->prec)
		ft_putchar(' ');
	if (pf->minus)
		ft_putchar('-');
	while (pf->prec-- > numlen)
		ft_putchar('0');
	while (++pbuf != &buf[32])
		ft_putchar(*pbuf);
}

void	print_s(t_pf *pf, va_list *ap)
{
	char	*s;
	int		slen;

	s = (char *)va_arg(*ap, void *);
	if (!s)
		s = "(null)";
	slen = ft_strlen(s);
	pf->prec = pf->prec < 0 ? slen : pf->prec;
	slen = get_min(slen, pf->prec);
	pf->count += get_max(slen, pf->width);
	while (pf->width-- > slen)
		ft_putchar(' ');
	while (*s && slen--)
		ft_putchar(*s++);
}

void	print_d(t_pf *pf, va_list *ap)
{
	long	num;

	num = va_arg(*ap, int);
	if (num < 0)
	{
		num = -num;
		pf->minus = TRUE;
	}
	print_num(pf, num, 10);
}

void	print_x(t_pf *pf, va_list *ap)
{
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	print_num(pf, num, 16);
}

int		types_proc(t_pf *pf, va_list *ap)
{
	if (pf->type == 's')
		print_s(pf, ap);
	else if (pf->type == 'd')
		print_d(pf, ap);
	else if (pf->type == 'x')
		print_x(pf, ap);
	else
		return (FALSE);
	return (TRUE);
}

int		specs_parser(t_pf *pf, va_list *ap, char **fmt)
{
	pf->width = 0;
	pf->prec = -1;
	pf->minus = FALSE;
	pf->type = '\0';

	(*fmt)++;
	pf->width = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;

	if (**fmt == '.')
		pf->prec = ft_atoi(++(*fmt));
	while (ft_isdigit(**fmt))
		(*fmt)++;

	pf->type = *(*fmt)++;
	
//	printf("\n%d - width\n", pf->width);
//	printf("\n%d - prec\n", pf->prec);
//	printf("\n%c - type\n", pf->type);
//	(void)ap;
	if (!types_proc(pf, ap))
		return (FALSE);
	return (TRUE);
}

int		ft_printf(const char *format, ... )
{
	t_pf		pf;
	va_list		ap;
	char		*fmt;

	pf.count = 0;
	fmt = (char *)format;
	va_start(ap, format);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (!specs_parser(&pf, &ap, &fmt))
			{
				va_end(ap);
				return (-1);
			}
		}
		else
		{
			ft_putchar(*fmt++);
			pf.count++;
		}
	}
	va_end(ap);
	return (pf.count);
}

// int main(void)
// {
// 	int orig = 0;
// 	int ft = 0;
// 	//orig = printf("%.4s %.4s %.4s\n", "toto", "0123456789", "tjehurthteutuiehteute");
// 	orig = printf("%7s%-5s\n", "hello", "world");

// 	ft = ft_printf("%7s%-5s\n", "hello", "world");
// 	//printf("%d %d\n", orig, ft);
// }

//int		main(void)
//{
//	int		a, b;
//
//
//
//	a = ft_printf(S);
//	printf("%d - ft_printed\n", a);
//
//	printf("\n");
//
//	b = printf(S);
//	printf("%d - printed\n", b);
//	return (0);
//}
