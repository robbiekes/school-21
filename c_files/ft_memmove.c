/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:45:15 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 21:05:21 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
    char *copy_to;
    char *copy_from;
    int i;
	
    i = 0;
    copy_to = (char *)dst;
    copy_from = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (src < dst)
	{
		i = len - 1;
		while (i >= 0)
		{
			copy_to[i] = copy_from[i];
			i--;
		}
	}
	else
	{
		while (len > 0)
		{
			copy_to[i] = copy_from[i];
			len--;
			i++;
		}
	}
    return (copy_to);
}

// int main(void)
// {
//     char dest[13] = "sfghjgf88888";
//     char src[8] = "6666d00";
// 	char str[20] = "123456789";

//     //ft_memmove(dest, src, 8);
//     printf("ft_memmove = %s\n", ft_memmove(str, str + 1, 3));
// 	printf("str -> %s\n", str);
// 	//printf("memmove = %s\n", memmove(dest, src, 5));
//     return (0);
// }