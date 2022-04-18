/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:12:54 by mgwyness          #+#    #+#             */
/*   Updated: 2022/02/14 15:47:19 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] != s2[i]) || s1[i] == '\0' || s2[i] == '\0')
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
