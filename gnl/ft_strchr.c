/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:57:00 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/27 16:25:07 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*arr;
	int		i;
	int		len;

	i = 0;
	arr = (char *)s;
	printf("s = %s\n", arr);
	len = ft_strlen(arr);
	while (i <= len)
	{
		if (arr[i] == (char)c)
			return (&arr[i]);
		i++;
	}
	return (0);
}
