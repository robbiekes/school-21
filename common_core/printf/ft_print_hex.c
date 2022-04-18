/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:03:08 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/20 16:58:44 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static char	ft_result(int tmp, int text_size)
{
	char	res;

	if (text_size == 0)
		res = 'A' + tmp - 10;
	else
		res = 'a' + tmp - 10;
	return (res);
}

int	ft_print_hex(unsigned int num, int text_size)
{
	char	arr[12];
	int		i;
	int		tmp;

	i = 0;
	if (num == 0)
		return (write(1, "0", 1));
	while (num > 0)
	{
		tmp = num % 16;
		if (tmp >= 0 && tmp < 10)
			arr[i] = '0' + tmp;
		else
			arr[i] = ft_result(tmp, text_size);
		i++;
		num = num / 16;
	}
	arr[i] = 0;
	while (--i >= 0)
		write(1, &arr[i], 1);
	return (ft_strlen(arr));
}
