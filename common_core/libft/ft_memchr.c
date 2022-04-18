/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:29:14 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/13 13:37:06 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*arr;
	int				i;
	int				len;

	arr = (unsigned char *)s;
	i = 0;
	len = ft_strlen(s);
	if (arr == NULL)
		return (NULL);
	while (n)
	{
		if (arr[i] == (unsigned char)c)
			return (&arr[i]);
		n--;
		i++;
	}
	return (NULL);
}
