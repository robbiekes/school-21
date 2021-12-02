/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:45:27 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/13 14:26:48 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_s;

	i = 0;
	len_d = 0;
	while (len_d < dstsize && dst[len_d])
		len_d++;
	len_s = ft_strlen(src);
	while (src[i] != '\0' && (i + len_d + 1) < dstsize)
	{
		dst[len_d + i] = src[i];
		i++;
	}
	if (dstsize > len_d)
		dst[len_d + i] = '\0';
	return (len_s + ft_min(len_d, dstsize));
}
