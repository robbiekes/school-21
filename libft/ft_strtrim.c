/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:38:15 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/12 19:59:58 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_similar(char a, const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (a == s[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_get_bytes(char const *s1, char const *set)
{
	int	start;
	int	k;
	int	end;
	int	i;

	end = 0;
	i = 0;
	k = 0;
	start = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && ft_similar(s1[i], set))
	{
		start++;
		i++;
	}
	while (k >= 0 && ft_similar(s1[k], set))
	{
		end++;
		k--;
	}
	k = ft_strlen(s1);
	if ((k - start - end) < 0)
		return (0);
	return (k - start - end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		index;
	int		i;
	int		size_str;

	if (s1 == 0)
		return (0);
	size_str = ft_get_bytes(s1, set);
	index = 0;
	i = 0;
	trimmed = (char *)malloc(sizeof(char) * (size_str + 1));
	if (trimmed == 0)
		return (0);
	while (s1[index] != '\0' && ft_similar(s1[index], set))
		index++;
	while (i < size_str)
	{
		trimmed[i] = s1[index];
		i++;
		index++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
