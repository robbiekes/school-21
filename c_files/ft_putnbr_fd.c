/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:01:43 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/10 19:30:36 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	int				temp;
	
	nbr = (unsigned int) n;
	if (n < 0)
		write(fd, "-", 1);
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	temp = (nbr % 10) + '0';
	write(fd, &temp, 1);
}