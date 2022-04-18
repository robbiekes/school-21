/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:41:29 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/13 13:27:23 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(const char *str)
{
	int	len;

	len = 0;
	while (*str == '0')
	{
		str++;
	}
	while (ft_isdigit(*str))
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	num;
	int			i;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (ft_numlen(&str[i]) > 19)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	return (num * sign);
}
