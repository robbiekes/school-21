/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:38:50 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/08 20:26:40 by mgwyness         ###   ########.fr       */
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

/* int main(void)
// {
// 	char dest1[100] = "dfdkjdkfj";
// 	char dest2[100] = "dfdkjdkfj";
// 	char src[11] = "123\000123";
// 	printf("%s\n", ft_memcpy(dest1, src, 7));
// 	printf("%s\n", memcpy(dest2, src, 7));
// 	return (0);
// }*/
