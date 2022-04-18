/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:05:07 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/21 13:36:23 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_print_hex(unsigned int num, int text_size);
int		ft_print_ptr(va_list ap);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_print_int(va_list ap);
int		ft_print_uint(va_list ap);
int		ft_print_str(va_list ap);
int		ft_print_char(va_list ap);
int		ft_spec_output(char c1, char c2, va_list ap);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);

#endif