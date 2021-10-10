/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:45:27 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/10 14:48:10 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	int	res;

	if (a < b)
		res = a;
	else
		res = b;
	return (res);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		len_d;
	int		len_s;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
    while(src[i] != '\0' && (i + len_d + 1) < dstsize)
    {
        dst[len_d + i] = src[i];
        i++;
    }
    while (src[i] != '\0')
        i++;
    dst[len_d + i] = '\0';
    return (len_s + ft_min(len_d, dstsize));
}
