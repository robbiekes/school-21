/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:38:39 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/20 14:57:26 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spec_output(char c1, char c2, va_list ap)
{
	if (c1 == '%' && (c2 == 'd' || c2 == 'i'))
		return (ft_print_int(ap));
	else if (c1 == '%' && c2 == 'u')
		return (ft_print_uint(ap));
	else if (c1 == '%' && c2 == 's')
		return (ft_print_str(ap));
	else if (c1 == '%' && c2 == 'c')
		return (ft_print_char(ap));
	else if (c1 == '%' && c2 == '%')
		return (write (1, "%%", 1));
	else if (c1 == '%' && c2 == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), 1));
	else if (c1 == '%' && c2 == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), 0));
	else if (c1 == '%' && c2 == 'p')
		return (ft_print_ptr(ap));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += (ft_spec_output(format[i], format[i + 1], args));
			i += 2;
		}
		else
			count += write(1, &format[i++], 1);
	}
	return (count);
}
