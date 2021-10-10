/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:45:01 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/09 15:34:47 by mgwyness         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize > 0)
	{
		while(dst[i] != '\0' && src[i] != '\0' && dstsize > 1)
		{
			dst[i] = src[i];
				i++;
				dstsize--;
		}
		dst[i] = '\0';
	}
	return (len);
}

// int main(void)
// {
// 	char *str = "hello !";
	
//     char dest1[100];
//     char dest2[100];
//     // char src[100];
// 	memset(dest1, 'A', 20);
// 	memset(dest2, 'A', 20);
//     printf("%zu\n", ft_strlcpy(dest1, str, 0));
// 	printf("s -> %s\n", dest1);
//     printf("%lu\n", strlcpy(dest2, str, 0));
// 	printf("s -> %s\n", dest2);
	
//     return (0);
// }