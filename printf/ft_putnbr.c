void	ft_putnbr(int n)
{
	int	temp;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10);
	temp = (n % 10) + '0';
	write(1, &temp, 1);
}

int main(void)
{
	ft_putnbr(3562);
}