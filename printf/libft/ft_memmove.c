/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:45:15 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/13 13:51:04 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*copy_to;
	char	*copy_from;
	int		i;

	i = 0;
	copy_to = (char *)dst;
	copy_from = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			copy_to[i] = copy_from[i];
	}
	else
	{
		while (len-- > 0)
		{
			copy_to[i] = copy_from[i];
			i++;
		}
	}
	return (copy_to);
}
