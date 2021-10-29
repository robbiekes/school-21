int	ft_str_len(char *reserved)
{
	int	len;

	len = 0;
	while (reserved[len] != '\n' && reserved[len] != '\0')
		len++;
	return (len);
}

char	*ft_create_line(char *reserved)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_str_len(reserved);
	if (reserved[len] == '\n')
		str = (char *)malloc(sizeof(char) * (len + 2));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (reserved[i] != '\n' && reserved[i] != '\0')
		str[i++] = reserved[len++];
	if (reserved[i] == '\0')
	{
		str[i] = '\0';
		free(reserved);
	}
	else
	{
		str[i] = '\n';
		str[i + 1] = '\0';
		ft_cut_str(reserved);
	}
	return (str);
}