/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:47:13 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/20 15:47:15 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(va_list ap)
{
	unsigned long long	size;
	int					tmp;
	int					count;

	count = 0;
	size = va_arg(ap, unsigned long long);
	tmp = 60;
	write(1, "0x", 2);
	if (size == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	while ((size >> tmp) % 16 == 0)
		tmp -= 4;
	while (tmp >= 0)
	{
		ft_print_hex(((size >> tmp) % 16), 1);
		tmp -= 4;
		count++;
	}
	return (count + 2);
}
