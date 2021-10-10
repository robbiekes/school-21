/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:41:29 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/09 17:12:26 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>


int	ft_atoi(const char *str) 
{
	char	*arr;
	int		sign;
	long int	num;
	int		i;

	sign = 1;
	i = 0;
	num = 0;
	arr = (char *)str;
	while(str[i] == ' ' || str[i] == '\t'|| str[i] == '\v' || str[i] == '\f' || 
		str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if(str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return num*sign;
}

int main(void)
{
	char n[40] = "99999999999999999999999999";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf("orig = %d\n", i1);
	printf("ft = %d\n", i2);
	return (0);
}