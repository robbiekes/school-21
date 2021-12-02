int ft_atoi(char *a)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 0;
	res = 0;
	while (a[i] && a[i] >= 9 && a[i] <= 13)
		i++;
	if (a[i] == '-')
		sign = -1;
	if (a[i] == '-' || a[i] == '+')
		i++;
	while (a[i] >= '0' && a[i] <= '9')
	{
		res = res * 10 + (a[i] - '0');
		i++;
	}
	return (res * sign);
}