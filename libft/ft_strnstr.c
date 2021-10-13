/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:12:39 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/13 14:30:19 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*to_search;
	char	*to_find;

	to_search = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	if (to_find[0] == '\0')
		return (to_search);
	while (to_search[i] != '\0' && (i + ft_strlen(to_find) - 1) < len)
	{
		j = 0;
		while (to_find[j] != '\0' && to_search[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&to_search[i]);
			j++;
		}
		i++;
	}
	return (0);
}
