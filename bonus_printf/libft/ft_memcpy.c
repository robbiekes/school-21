/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:38:50 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/12 18:57:12 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*copy_to;
	char	*copy_from;
	int		i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	copy_from = (char *)src;
	copy_to = (char *)dst;
	while (n > 0)
	{
		copy_to[i] = copy_from[i];
		i++;
		n--;
	}
	return (dst);
}
