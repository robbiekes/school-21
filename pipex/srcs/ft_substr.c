/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:21:19 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/07 17:58:07 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static int	ft_min(int a, int b)
{
	int	res;

	if (a < b)
		res = a;
	else
		res = b;
	return (res);
}

//char	*ft_substr(char **s, unsigned int start, int len)
//{
//	char			*substr;
//	unsigned int	i;
//	unsigned int	count;

//	i = 0;
//	if (s == 0)
//		return (0);
//	count = ft_strlen(s);
//	if (start >= count || len == 0)
//		return (ft_strdup(""));
//	count = ft_min(count - start, len) + 1;
//	substr = (char *)malloc(sizeof(char) * count);
//	if (substr == 0)
//		return (0);
//	while (s[start] != '\0' && i < len)
//	{
//		substr[i] = s[start];
//		i++;
//		start++;
//	}
//	substr[i] = '\0';
//	return (substr);
//}

void ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest != 0)
	{
		while (src[i] != '\0')
		{
			*(dest + i) = src[i];
			i++;
		}
		*(dest + i) = '\0';
	}
	exit(1);
}
