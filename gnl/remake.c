
char *buf;
buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
if (!read(fd, buf, BUFFER_SIZE))
{
	free(buf);
	return (0);
}
while (1)
	