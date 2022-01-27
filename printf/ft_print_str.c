/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:42:54 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/20 16:10:47 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_print_str(va_list ap)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = va_arg(ap, char *);
	if (tmp == 0)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (tmp[i] != '\0')
	{
		write(1, &tmp[i], 1);
		i++;
	}
	return (ft_strlen(tmp));
}
