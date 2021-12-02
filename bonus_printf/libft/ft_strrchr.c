/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:39:56 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/13 14:31:37 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*arr;
	int		len;

	arr = (char *)s;
	len = ft_strlen(arr);
	if (arr == NULL)
		return (NULL);
	while (len >= 0)
	{
		if (arr[len] == (char)c)
			return (&arr[len]);
		len--;
	}
	return (NULL);
}
