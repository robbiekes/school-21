#include "get_next_line.h"

char	*ft_next_line(char *reserved)
{
	int		i;
	int 	j;
	char	*dup;
	int		len;

	i = 0;
	len = ft_strlen(reserved);
	while (reserved[i] != '\0' && reserved[i] != '\n')
		i++;
	if (reserved[i] == '\0')
	{
		free(reserved);
		return (0);
	}
	dup = (char *)malloc(sizeof(char) * (len - i + 1));
	if (dup == 0)
		return (0);
	i++;
	j = 0;
	while (reserved[i])
	{
		dup[j] = reserved[i];
		i++;
		j++;
	}
	dup[j] = '\0';
	free(reserved);
	return (dup);
}
