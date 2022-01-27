/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:39:16 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/20 16:05:51 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_putnbr(int n)
{
	long long	temp;
	long long	tmp_n;

	tmp_n = (long long)n;
	if (tmp_n < 0)
	{
		tmp_n = -tmp_n;
		write(1, "-", 1);
	}
	if (tmp_n >= 10)
		ft_putnbr(tmp_n / 10);
	temp = (tmp_n % 10) + '0';
	write(1, &temp, 1);
	return (ft_numlen(n));
}
