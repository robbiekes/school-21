#include <stdio.h>
#include <stdlib.h>

static int	ft_len(long long n)
{
	int count;
	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int size;
	int i;
	char *arr;
	long long nbr;

	nbr = (long long)n;
	i = 0;
	size = ft_len(nbr);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (arr == 0)
		return(0);
	arr[size] = '\0';
	if (nbr < 0)
	{
		arr[0] = '-';
		nbr = -nbr;
		i++;
	}
	// printf("%s\n", arr);
	while(size > i)
	{
		// printf("size -> %d\n", size - 1);
		// printf("n %% 10 -> %d\n", n % 10);
		arr[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	return (arr);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }