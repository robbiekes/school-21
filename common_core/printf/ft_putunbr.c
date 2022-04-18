/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:39:57 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/21 13:43:19 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_putunbr(unsigned int n)
{
	unsigned int	nbr;
	int				count;
	int				temp;

	nbr = (unsigned int) n;
	count = 0;
	if (nbr >= 10)
		ft_putunbr(nbr / 10);
	temp = (nbr % 10) + '0';
	write(1, &temp, 1);
	return (ft_numlen(n));
}
