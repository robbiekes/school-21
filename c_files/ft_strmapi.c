/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgwyness <mgwyness@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:53:23 by mgwyness          #+#    #+#             */
/*   Updated: 2021/10/10 20:05:27 by mgwyness         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	i;
	int	len;
	char *arr;
	
	if (s == 0 || f == 0)
		return (0);
	i = 0;
	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	while (s[i] != '\0')
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
