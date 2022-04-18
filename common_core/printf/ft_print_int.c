/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:42:36 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/20 15:46:59 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list ap)
{
	int	tmp;
	int	count;

	tmp = va_arg(ap, int);
	count = ft_putnbr(tmp);
	return (count);
}
