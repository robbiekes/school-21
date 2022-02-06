/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:21:19 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/06 19:36:10 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strdup(char *s1)
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

char	*ft_substr(char **s, unsigned int start, int len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	count;

	i = 0;
	if (s == 0)
		return (0);
	count = ft_strlen(s);
	if (start >= count || len == 0)
		return (ft_strdup(""));
	count = ft_min(count - start, len) + 1;
	substr = (char *)malloc(sizeof(char) * count);
	if (substr == 0)
		return (0);
	while (s[start] != '\0' && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
