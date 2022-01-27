/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:42:44 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/19 18:27:02 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list ap)
{
	unsigned int	tmp;
	int				count;

	tmp = va_arg(ap, unsigned int);
	count = ft_putunbr(tmp);
	return (count);
}
