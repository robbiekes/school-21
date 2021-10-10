/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:12:39 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/09 17:03:50 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

// size_t	ft_strlen(const char *s)
// {
	
// 	size_t	i;

// 	i = 0;
// 	while(s[i] != '\0'){
// 		i++;
// 	}
// 	return i;
// }

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
			if (to_find[j+1] == '\0')
				return (&to_search[i]);
			j++;
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	// char *s1 = "AAAAAAAAAAAAA";
// 	// size_t max = strlen(s1);
// 	// char *i1 = strnstr(s1, s1, max);
// 	// char *i2 = ft_strnstr(s1, s1, max);
	
// 	char *s1 = "MZIRIBMZIRIBMZE123";
// 	char *s2 = "MZIRIBMZE";
// 	size_t max = strlen(s2);
// 	char *i1 = strnstr(s1, s2, max);
// 	char *i2 = ft_strnstr(s1, s2, max);
// 	printf("orig = %s\n", i1);
// 	printf("ft = %s\n", i2);
//     return (0);
// }