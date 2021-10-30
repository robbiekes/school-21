/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:39:00 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/30 19:39:00 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fill(char *buf, char *reserved, int fd)
{
	int	count;

	count = 0;
	while (!ft_strchr(reserved, '\n'))
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count <= 0)
		{
			free(buf);
			if (count == 0 && reserved[0] != '\0')
				return (reserved);
			free(reserved);
			return (0);
		}
		reserved = ft_strjoin(reserved, buf, count);
	}
	free(buf);
	return (reserved);
}

void	ft_cut_str(char *reserved)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (reserved[i] != '\n')
		i++;
	i++;
	while (reserved[i] != '\0')
	{
		reserved[j] = reserved[i];
		j++;
		i++;
	}
	reserved[j] = '\0';
}

char	*ft_create_line(char **reserved)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while ((*reserved)[len] != '\n' && (*reserved)[len] != '\0')
		len++;
	if ((*reserved)[len] == '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while ((*reserved)[i] != '\n' && (*reserved)[i] != '\0')
		str[len++] = (*reserved)[i++];
	if ((*reserved)[i] == '\0')
	{
		str[i] = '\0';
		free(*reserved);
		*reserved = 0;
		return (str);
	}
	str[i] = '\n';
	str[i + 1] = '\0';
	ft_cut_str(*reserved);
	return (str);
}

char	*ft_read_bytes(int fd, char *reserved)
{
	char	*buf;

	if (reserved == 0)
	{
		reserved = (char *)malloc(sizeof(char));
		reserved[0] = '\0';
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (buf == 0)
	{
		free(reserved);
		return (0);
	}
	reserved = ft_read_fill(buf, reserved, fd);
	return (reserved);
}

char	*get_next_line(int fd)
{
	static char	*reserved = 0;
	char		*arr;

	reserved = ft_read_bytes(fd, reserved);
	if (reserved == 0)
	{
		return (0);
	}
	arr = ft_create_line(&reserved);
	return (arr);
}
