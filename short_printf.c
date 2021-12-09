#include <unistd.h>
#include <stdarg.h>
static int ft_nbrlen(long n, int base_len)
{
    int i = 1;
    while(n >= base_len)
    {
        n /= base_len;
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
    va_list ap;
    char *str;
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
    str = (char *)format;
    length = 0;
    while (*str)
    {
        if (*str == '%')
        {
            width = 0;
            prec = -1;
            neg = 0;
            len = 0;
            zeros = 0;
            spaces = 0;
            while (*str >= '0' && *str <= '9')
            {
                width = width * 10 + (*str - '0');
                str++;
            }
            if (*str == '.')
            {
                str++;
                prec = 0;
                while(*str >= '0' && *str <= '9')
                {
                    prec = prec * 10 + (*str - '0');
                    str++;
                }
            }
            if (*str == 's')
            {
                s = va_arg(ap, char *);
                if(!s)
                    s = ("null");
                while (s[len])
                    len++;
            }
            if (*str == 'd')
            {
                nbr = va_arg(ap, int);
                if (nbr < 0)
                {
                    nbr = -nbr;
                    neg = 1;
                }
                len = ft_nbrlen(nbr, 10) + neg;
            }
            if (*str == 'x')
            {
                nbr = va_arg(ap, unsigned);
                len = ft_nbrlen(nbr, 16);
            }
            if (prec >= len && *str != 's')
                zeros = prec - len + neg;
            else if (prec > -1 && prec < len && *str == 's')
                len = prec;
            else if (prec == 0 && (*str == 's' || nbr == 0))
                len = 0;
            spaces = width - zeros - len;
            while (spaces-- > 0)
                length += write(1, " ", 1);
            if (neg)
                write (1, "-", 1);
            while (zeros-- > 0)
                length += write(1, "0", 1);
            if (*str == 's')
                write(1, s, len);
            else if (*str == 'd')
                ft_putnbr(nbr, 10, "0123456789");
            else if (*str == 'x')
                ft_putnbr(nbr, 16, "0123456789abcdef");
            length += len;
        }
        else
            length += write(1, str, 1);
        str++;
    }
    va_end(ap);
    return (0);
}
