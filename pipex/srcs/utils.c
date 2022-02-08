/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:31:27 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/08 15:27:31 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dst, char *src)
{
	int		i;
	int		len_d;

	i = 0;
	len_d = ft_strlen(dst);
	while (src[i] != '\0')
	{
		dst[len_d + i] = src[i];
		i++;
	}
	dst[len_d + i] = '\0';
	return (dst);
}

char	*pathjoin(char *s1, char *s2)
{
	char	*arr;
	int		len_s1;
	int		len_s2;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 2);
	if (arr == 0)
		return (0);
	arr[0] = 0;
	ft_strcat(arr, s1);
	ft_strcat(arr, "/");
	ft_strcat(arr, s2);
	return (arr);
}

char	*ft_strdup(char *s1)
{
	char	*arr;
	int		i;
	char	*dup;
	int		len;

	arr = (char *)s1;
	len = ft_strlen(arr);
	i = 0;
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == 0)
		return (0);
	while (arr[i])
	{
		dup[i] = arr[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
