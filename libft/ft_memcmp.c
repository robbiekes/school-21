/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:24:01 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/13 13:37:32 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*arr1;
	char	*arr2;
	size_t	i;

	i = 0;
	arr1 = (char *)s1;
	arr2 = (char *)s2;
	while (i < n)
	{
		if (arr1[i] != arr2[i])
			return ((int)(unsigned char)arr1[i] - (unsigned char)arr2[i]);
		i++;
	}
	return (0);
}
