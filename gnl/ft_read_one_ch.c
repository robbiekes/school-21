void ft_createlst(char buf)
{
	struct *lines;

	lines = malloc(sizeof(struct) * 10);
		char *array;
		unsigned int	line_size;
		unsigned int	memory;
	
}

char *ft_push_symb(struct lines *one_line, char buf)
{
	one_line->array = buf;
	one_line->line_size++;
	if (one_line->line_size == one_line->memory)

}

int ft_read_one_ch(int fd, char *ch_ptr)
{
	char *buf;
	int	i;
	static int	n;

	if (!read(fd, buf, 15))
	{
		free(buf);
		return (0);
	}
	i = 0;
	n = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		ch_ptr[i] = buf[i];
	}

}