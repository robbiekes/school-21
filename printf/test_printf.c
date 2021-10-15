#include <stdio.h>
#include <stdarg.h>

int ft_max(unsigned int num, ...)
{
	va_list ap;
	int max;
	int tmp;

	max = -9999;
	tmp = 0;
	va_start(ap, num);
	while (num > 0)
	{
		tmp = va_arg(ap, int);
		if (tmp > max)
			max = tmp;
		num--;
	}
	va_end(ap);
	return (max);
}

int main(void)
{
	printf("max = %d\n", ft_max(4, 7, -3, 1, -100));
	return (0);
}