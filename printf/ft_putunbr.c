void	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				temp;

	nbr = (unsigned int) n;
	if (n < 0)
	{
		nbr = -n;
		write(1, "-", 1);
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10);
	temp = (nbr % 10) + '0';
	write(1, &temp, 1);
}